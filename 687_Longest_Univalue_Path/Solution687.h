#ifndef SOLUTION687_H_
#define SOLUTION687_H_
#include "TreeNode.h"
class Solution {
    private:
        int longest_val;
    public:
        int longestUnivaluePath(TreeNode* root);
        int dfs(TreeNode* root);
};

#endif
