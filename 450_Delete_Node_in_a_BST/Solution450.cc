#include "Solution450.h"
#include "TreeNode.h"
#include <stack>
#include <vector>
using namespace std;

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
