#ifndef SOLUTION235_H_
#define SOLUTION235_H_
#include <vector>
#include "TreeNode.h"

class Solution {
    public:
        std::vector<int> postorderTraversal(TreeNode*root);
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};

#endif
