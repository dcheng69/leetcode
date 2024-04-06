#ifndef SOLUTION889_H_
#define SOLUTION889_H_
#include "TreeNode.h"
#include <vector>
using std::vector;

class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder);
        vector<int> subVec(vector<int>& i_vec, vector<int>::iterator start, unsigned int count);
};

#endif
