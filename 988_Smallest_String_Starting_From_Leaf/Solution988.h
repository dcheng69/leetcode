#ifndef SOLUTION988_H_
#define SOLUTION988_H_
#include <string>
#include "TreeNode.h"

class Solution {
    public:
        std::string smallestFromLeaf(TreeNode* root);
        void dfs(TreeNode* root, std::string str, std::string &smallest);
};

#endif
