#include <iostream>
#include <stack>
#include "Solution437.h"
using namespace std;

/**
 * Below is a recursive solution, can use iterative solution to substitute
 */
int pathSumRootRecursive(TreeNode* root, int targetSum) {
    int sum = 0;
    if (!root) {
        return 0;
    }

    if (root->val == targetSum) {
        sum = 1;
    }

    return sum + \
        pathSumRootRecursive(root->left, targetSum-root->val) + \
        pathSumRootRecursive(root->right, targetSum-root->val);
}

/**
 * Below is a postorder Traversal solution
 */
vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (!root)
        return i_vec;

    stack<TreeNode*> t_stk;
    TreeNode* last_visited = nullptr;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        if (root->right && last_visited!=root->right) {
            root = root->right;
        } else {
            // either visited the right node, or just leaf node
            i_vec.push_back(root->val);
            t_stk.pop();
            last_visited = root;
            root = nullptr;
        }
    }
    return i_vec;
}


/**
 * Below is an iterative solution, using postorder traversal as a base function
 */
int pathSumRootIterative(TreeNode* root, int targetSum) {
    long long int sum = 0;
    int num_path = 0;
    if (!root)
        return num_path;

    stack<TreeNode*> t_stk;
    TreeNode* last_visited = nullptr;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            sum+=root->val;
            if (sum == targetSum)
                num_path++;
            root = root->left;
        }

        root = t_stk.top();
        if (root->right && last_visited != root->right) {
            root = root->right;
        } else {
            // leaf node or just visit right node
            sum -= root->val;
            t_stk.pop();
            last_visited = root;
            root = nullptr;
        }
    }
    return num_path;
}

int Solution::pathSum(TreeNode* root, int targetSum) {
    // traverse all the node and add them all together
    int sum = 0;

    // inorderTraversal
    stack<TreeNode*> t_stk;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        t_stk.pop();
        sum += pathSumRootIterative(root, targetSum);
        root = root->right;
    }
    return sum;
}

