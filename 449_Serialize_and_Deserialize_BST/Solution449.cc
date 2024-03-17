#include <sstream>
#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
#include <thread>
#include "Solution449.h"
#include "TreeNode.h"
using namespace std;

// Encodes a tree to a single string.
std::string Solution::serialize(TreeNode* root) {
    string str;
    if (!root)
        return str;

    string str_in;
    // inorderTraversal save to string
    thread inorder_thread([&]() {
            TreeNode* in_root = root;
            stack<TreeNode*> t_stk_in;
            while (in_root || !t_stk_in.empty()) {
            while (in_root) {
            t_stk_in.push(in_root);
            in_root = in_root->left;
            }

            in_root = t_stk_in.top();
            t_stk_in.pop();
            str_in += to_string(in_root->val);
            str_in += ",";
            in_root = in_root->right; }

            // remove the comma at the end
            str_in.pop_back();
            });

    string str_po;
    // postorderTraversal save to string
    thread postorder_thread([&]() {
            TreeNode* po_root = root;
            stack<int> i_stk;
            stack<TreeNode*> t_stk_po;
            t_stk_po.push(po_root);
            while (!t_stk_po.empty()) {
            po_root = t_stk_po.top();
            t_stk_po.pop();
            i_stk.push(po_root->val);

            if (po_root->left) {
            t_stk_po.push(po_root->left);
            }
            if (po_root->right) {
            t_stk_po.push(po_root->right);
            }
            }
            while (!i_stk.empty()) {
            str_po += to_string(i_stk.top());
            str_po += ",";
            i_stk.pop();
            }

            // remove the comma at the end
            str_po.pop_back();
            });

    // wait for both threads to finish
    inorder_thread.join();
    postorder_thread.join();

    // combine the str together
    str = str_in + "$" + str_po;

    return str;
}

// Decodes your encoded data to tree.
TreeNode* Solution::deserialize(std::string data) {
    TreeNode* p_root = nullptr;
    if (data.size() == 0)
        return p_root;

    auto pos = find(data.begin(), data.end(), '$');
    if (pos == data.end()) {
        cerr << "invalid inputs!" << endl;
        return p_root;
    }

    string inorder_str(data.begin(), pos);
    string postorder_str(pos+1, data.end());
    vector<int> inorder;
    vector<int> postorder;

    thread inorder_thread([&]() {
            string num_str;
            stringstream inorder_ss(inorder_str);
            while (getline(inorder_ss, num_str, ',')) {
            inorder.push_back(stoi(num_str));
            }
            });

    thread postorder_thread([&]() {
            string num_str;
            stringstream postorder_ss(postorder_str);
            while (getline(postorder_ss, num_str, ',')) {
            postorder.push_back(stoi(num_str));
            }
            });

    // wait for both threads to finish
    inorder_thread.join();
    postorder_thread.join();

    return buildTree(inorder, postorder);
}

std::vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if(!root)
        return i_vec;

    stack<TreeNode*> t_stk;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        t_stk.pop();
        i_vec.push_back(root->val);
        root = root->right;
    }
    return i_vec;
}

std::vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (!root)
        return i_vec;

    stack<int> i_stk;
    stack<TreeNode*> t_stk;
    t_stk.push(root);
    while (!t_stk.empty()) {
        root = t_stk.top();
        t_stk.pop();
        i_stk.push(root->val);

        if (root->left) {
            t_stk.push(root->left);
        }
        if (root->right) {
            t_stk.push(root->right);
        }
    }

    while (!i_stk.empty()) {
        i_vec.push_back(i_stk.top());
        i_stk.pop();
    }
    return i_vec;
}

vector<int> subVectorUsingIterators(const vector<int>& originalVector, int startIndex, int length) {
    vector<int> subVec;
    // Check if the startIndex is within bounds
    if (startIndex >= 0 && startIndex < originalVector.size() && length > 0) {
        // Resize the subVec to accommodate 'length' elements
        subVec.resize(length);
        // Copy elements from originalVector to subVec using iterators
        copy(originalVector.begin() + startIndex, originalVector.begin() + startIndex + length, subVec.begin());
    }
    return subVec;
}

// Using iterators to get Index for a given value in vector
int findVecIndex(const vector<int>& vec, int value) {
    auto it = find(vec.begin(), vec.end(), value); // Find the iterator pointing to the value
    if (it != vec.end()) {
        return distance(vec.begin(), it); // Calculate the index using distance
    }
    return -1; // Return -1 if value is not found
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* p_root = nullptr;
    if (postorder.size() == 0 && inorder.size() == 0)
        return p_root;

    p_root = new TreeNode(postorder[postorder.size() - 1]);
    int inorder_root_index = findVecIndex(inorder, p_root->val);
    int left_tree_length = inorder_root_index;
    int right_tree_length = inorder.size() - left_tree_length - 1;
    vector<int> inorder_left_vec = subVectorUsingIterators(inorder, 0, left_tree_length);
    vector<int> inorder_right_vec = subVectorUsingIterators(inorder, inorder_root_index + 1, right_tree_length);
    vector<int> post_left_vec = subVectorUsingIterators(postorder, 0, left_tree_length);
    vector<int> post_right_vec = subVectorUsingIterators(postorder, left_tree_length, right_tree_length);

    p_root->left = buildTree(inorder_left_vec, post_left_vec);
    p_root->right = buildTree(inorder_right_vec, post_right_vec);

    return p_root;
}
