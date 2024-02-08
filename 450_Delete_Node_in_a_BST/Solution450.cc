#include "Solution450.h"
#include "TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//#define DEBUG
#define SOLUTION_2

#ifdef SOLUTION_1
/**
 * @brief Recursive version of the code
 *
 * @param root
 * @param key
 *
 * @return 
 */
TreeNode* Solution::deleteNode(TreeNode* root, int key) {
    if (!root) {
        return nullptr;
    }

    // find the Node
    if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else {
        // found the node delete!

        // no child node
        if (!root->left && !root->right) {
            return nullptr;
        } else if (root->left && root->right) {
            // two child nodes
            TreeNode* temp = root->left;
            while (temp->right) {
                temp =  temp->right;
            }
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
            return root;
        } else {
        // one child node
            return root->left ? root->left : root->right;
        }

    }
    return root;
}
#endif // SOLUTION_1
       //
#ifdef SOLUTION_2
/**
 * @brief Non recursive, or partly recursive version of the code
 *
 * @param root
 * @param key
 *
 * @return
 */
TreeNode* Solution::deleteNode(TreeNode* root, int key) {
    if (!root)
        return nullptr;

    TreeNode* last = nullptr;
    TreeNode* curr = root;
    bool find = false;
    while (curr) {
        if (curr->val > key) {
            // search in the left child TreeNode
#ifdef DEBUG
            cout << "turn to the left node! \n";
#endif // !DEBUG
            last = curr;
            curr = curr->left;
        } else if (curr->val < key) {
            // search in the right child TreeNode
#ifdef DEBUG
            cout << "turn to the right node! \n";
#endif // !DEBUG
            last = curr;
            curr = curr->right;
        } else if (curr->val == key) {
            // find the node with the key value
#ifdef DEBUG
            cout << "Node found is:" << curr->val << endl;
#endif // !DEBUG
            find = true;
            break;
        }
    }

    if (find) {
        // leaf node
        if (!curr->left && !curr->right) {
            if (!last) {
                return nullptr;
            } else if (last->left == curr) {
                last->left = nullptr;
            } else if (last->right == curr) {
                last->right = nullptr;
            }
        } else if (curr->left && curr->right) {
            // two child nodes
            TreeNode* temp = curr->left;
            while (temp->right) {
                temp = temp->right;
            }

            curr->val = temp->val;
            curr->left = deleteNode(curr->left, temp->val);
        } else {
            // only one child node
            if (!last) {
                return curr->left ? curr->left : curr->right;
            } else if (last->left == curr) {
                last->left = curr->left ? curr->left : curr->right;
            } else if (last->right == curr) {
                last->right = curr->left ? curr->left : curr->right;
            }
        }
    }

    return root;
}

#endif // SOLUTION_2

/**
 * @brief Non recursive version of inorderTraverasl
 *
 * @param root, the root node of the Tree
 *
 * @return  vector contains the inorderTraversal
 */
std::vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (!root) {
        return i_vec;
    }

    stack<TreeNode*> t_stk;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        t_stk.pop();
        i_vec.push_back(root->val);
        if (!root->right) {
            root = nullptr;
        } else {
            root = root->right;
        }
    }
    return i_vec;
}
