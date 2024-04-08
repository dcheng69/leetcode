#ifndef SOLUTION894_H_
#define SOLUTION894_H_
#include <unordered_map>
#include <vector>
#include "TreeNode.h"
class Solution {
    private:
        std::unordered_map<int, std::vector<TreeNode*>> hash_map;
    public:
        std::vector<TreeNode*> allPossibleFBT(int n);
};

#endif
