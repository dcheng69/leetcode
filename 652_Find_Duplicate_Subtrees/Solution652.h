#ifndef SOLUTION652_H_
#define SOLUTION652_H_
#include <string>
#include <unordered_map>
#include <vector>
#include "TreeNode.h"

class Solution {
    private:
        std::unordered_map<std::string, int> hash_map;
        std::vector<TreeNode*> t_vec;
    public:
        std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
        std::string tree2str(TreeNode* root);
        std::vector<int> preorderTraversal(TreeNode* root);
};

#endif
