#include <iostream>
#include <queue>
#include "Solution199.h"
using namespace std;

vector<int> Solution::rightSideView(TreeNode* root) {
    vector<int> i_vec;
    if (!root)
        return i_vec;

    queue<TreeNode*> t_que;
    t_que.push(root);
    while (!t_que.empty()) {
        int size = t_que.size();
        while (size--) {
            root = t_que.front();
            t_que.pop();
            if (root->left)
                t_que.push(root->left);
            if (root->right)
                t_que.push(root->right);

            if (size == 0)
                i_vec.push_back(root->val);
        }
    }
    return i_vec;
}
