#ifndef SOLUTION1080_H_
#define SOLUTION1080_H_
#include "TreeNode.h"

class Solution {
    public:
        TreeNode* sufficientSubset(TreeNode* root, int limit);
        TreeNode* dfs(TreeNode* root, int limit, int sum);
};

#endif
