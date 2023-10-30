#include <iostream>
#include <queue>
#include <climits>
#include "TreeNode.h"
#include "ErrorNo.h"
using namespace std;

struct TreeNode* ConstructTreeNode(const vector<string>& s_vec, const string null_denotation="null") {
    TreeNode* p_root;
    vector<TreeNode*> tree_vec;

    if (s_vec.size() == 0)
        return nullptr;
    // calculate tree structure from index
    // left child --> (2n+1)
    // right child --> (2n+2)
    p_root = new TreeNode(stoi(s_vec[0]));
    tree_vec.push_back(p_root);
    for(int i=0; i<s_vec.size(); ++i) {
        TreeNode* p_temp = tree_vec[i];
        int left_index = 2*i+1, right_index = 2*i+2;
        if(left_index < s_vec.size() && s_vec[left_index] != null_denotation && p_temp != nullptr) {
            TreeNode* p_left = new TreeNode(stoi(s_vec[left_index]));
            p_temp ->left = p_left;
            tree_vec.push_back(p_left);
        }

        if (right_index < s_vec.size() && s_vec[right_index] != null_denotation && p_temp != nullptr) {
            TreeNode* p_right = new TreeNode(stoi(s_vec[right_index]));
            p_temp ->right = p_right;
            tree_vec.push_back(p_right);
        }
    }

    return p_root;
}

vector<string> ConstructVector(TreeNode* p_root) {
    // use queue to genereate layer traverse
    vector<string> s_vec;
    if (p_root == nullptr)
        return s_vec;
    s_vec.push_back(to_string(p_root->val));

    queue<TreeNode*> tree_que;
    tree_que.push(p_root);

    int max_depth = MaxTreeDepth(p_root);
    // layer traverse
    for (int i=0; i<max_depth-1; ++i) {
        int level_size = tree_que.size();
        for (int j=0; j<level_size; ++j) {
            TreeNode* p_tree_node = tree_que.front();
            tree_que.pop();
            if (p_tree_node == nullptr) {
                // left and right are nullptr
                tree_que.push(nullptr);
                tree_que.push(nullptr);
                s_vec.push_back("null");
                s_vec.push_back("null");
                continue;
            }
            // push all its child to queue
            if (p_tree_node->left != nullptr) {
                tree_que.push(p_tree_node->left);
                s_vec.push_back(to_string(p_tree_node->left->val));
            } else {
                tree_que.push(nullptr);
                s_vec.push_back("null");
            }
            if (p_tree_node->right != nullptr) {
                tree_que.push(p_tree_node->right);
                s_vec.push_back(to_string(p_tree_node->right->val));
            } else {
                tree_que.push(nullptr);
                s_vec.push_back("null");
            }
        }
    }

    return s_vec;
}

int SmartTreeNode::FreeTree(TreeNode* p_tree_node) {
    int ret = SUCCESS;
    queue<TreeNode*> tree_que;
    // free recursively
    if (p_tree_node == nullptr)
        return ret;

    tree_que.push(p_tree_node);
    while(!tree_que.empty()) {
        TreeNode* p_root = tree_que.front();
        tree_que.pop();
        if (p_root->left != nullptr) {
            tree_que.push(p_root->left);
        }
        if (p_root->right != nullptr) {
            tree_que.push(p_root->right);
        }
        free(p_root);
        p_root = nullptr;
    }

    return ret;
}

int MaxTreeDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    // find the max depth non recursively
    int max_depth = 0;
    queue<TreeNode*> node_queue;
    node_queue.push(root);

    while (!node_queue.empty()) {
        int level_size = node_queue.size();
        for (int i=0; i<level_size; ++i) {
            TreeNode* curr_root = node_queue.front();
            node_queue.pop();

            if (curr_root->left != nullptr) {
                node_queue.push(curr_root->left);
            }

            if(curr_root->right != nullptr) {
                node_queue.push(curr_root->right);
            }
        }
        max_depth++;
    }
    return max_depth;
}

int MaxTreeValue(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    // find the max depth non recursively
    int max_value= root->val;
    queue<TreeNode*> node_queue;
    node_queue.push(root);

    while (!node_queue.empty()) {
        int level_size = node_queue.size();
        for (int i=0; i<level_size; ++i) {
            TreeNode* curr_root = node_queue.front();
            node_queue.pop();

            if (curr_root->left != nullptr) {
                max_value = max_value>curr_root->left->val ? max_value : curr_root->left->val;
                node_queue.push(curr_root->left);
            }

            if(curr_root->right != nullptr) {
                max_value = max_value>curr_root->right->val ? max_value : curr_root->right->val;
                node_queue.push(curr_root->right);
            }
        }
    }
    return max_value;
}
