#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include "Solution337.h"
using namespace std;

long long int maxRob(TreeNode* root, unordered_map<TreeNode*, int>&hash) {
    if(!root)
        return 0;

    if (hash.find(root) != hash.end())
        return hash[root];

    long long int sum = root->val;
    if (root->left) {
        sum = sum + maxRob(root->left->left, hash) + maxRob(root->left->right, hash);
    }
    if (root->right) {
        sum = sum + maxRob(root->right->left, hash) + maxRob(root->right->right, hash);
    }
    // choose the max between taking the current node sum and not takeing it
    sum = max(sum, maxRob(root->left, hash) + maxRob(root->right, hash));
    return hash[root] = static_cast<int>(sum);
}

int Solution::rob(TreeNode* root) {
    unordered_map<TreeNode*, int> hash;
    return static_cast<int>(maxRob(root, hash));
}
