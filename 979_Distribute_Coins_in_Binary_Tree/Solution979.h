#ifndef SOLUTION979_H_
#define SOLUTION979_H_
#include "TreeNode.h"
class Solution {
    public:
        int distributeCoins(TreeNode* root);
        int traverse(TreeNode* root, int &moves);
};

#endif
