#include "Solution1080.h"
using namespace std;

TreeNode* Solution::sufficientSubset(TreeNode* root, int limit) {
    return dfs(root, limit, 0);
}

TreeNode* Solution::dfs(TreeNode* root, int limit, int sum) {
    if (!root)
        return nullptr;

    if (!root->left && !root->right) {
        // leaf node
        if (root->val + sum < limit)
            return nullptr;
        else
         return root;
    }

    TreeNode* left = dfs(root->left, limit, sum+root->val);
    TreeNode* right = dfs(root->right, limit, sum+root->val);
    if (!left) {
        root->left = nullptr;
    }
    if (!right) {
        root->right = nullptr;
    }
    if (!left && !right) {
        return nullptr;
    }
    return root;
}
