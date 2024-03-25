#ifndef SOLUTION655_H_
#define SOLUTION655_H_
#include <vector>
#include <string>
#include "TreeNode.h"

class Solution {
    private:
        int height;
    public:
        int findTreeHeight(TreeNode* root);
        std::vector<std::vector<std::string>> printTree(TreeNode* root);
        void fillValueInTree(TreeNode* root, std::vector<std::vector<std::string>> &str_vec_vec, int row, int col);
};

#endif
