#ifndef SOLUTION508_H_
#define SOLUTION508_H_
#include <vector>
#include "TreeNode.h"

class Solution {
    public:
        std::vector<int> inorderTraversal(TreeNode* root);
        long long int calSubTreeSum(TreeNode* root);
        std::vector<int> findFrequentTreeSum(TreeNode* root);
};

#endif
