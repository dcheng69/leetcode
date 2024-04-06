#include "Solution687.h"
using namespace std;

int Solution::longestUnivaluePath(TreeNode* root) {
    longest_val = 0;
    dfs(root);
    return longest_val == 0 ? 0 : longest_val - 1;
}

int Solution::dfs(TreeNode* root) {
    if (!root)
        return -1;
    if (!root->left && !root->right)
        return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);
    int temp_path = 1;
    if (root->left && root->val == root->left->val) {
        temp_path = max(temp_path, 1+left);
    }
    if (root->right && root->val == root->right->val) {
        temp_path = max(temp_path, 1+right);
    }
    longest_val = max(longest_val, temp_path);
    if (root->left && root->right && root->val == root->left->val && root->val == root->right->val) {
        longest_val = max(longest_val, 1+left+right);
    }
    return temp_path;
}
