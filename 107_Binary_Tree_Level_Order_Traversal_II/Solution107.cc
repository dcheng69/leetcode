#include <iostream>
#include <queue>
#include <stack>
#include "Solution107.h"
using namespace std;

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret_vec;
    if (root == nullptr)
        return ret_vec;

    stack<vector<int>> ret_stk;
    queue<TreeNode*> t_que;
    t_que.push(root);
    while (!t_que.empty()) {
        int level_size = t_que.size();
        vector<int> i_vec;
        for (int i=0; i<level_size; i++) {
            TreeNode* curr_root = t_que.front();
            t_que.pop();
            if (curr_root) {
                i_vec.push_back(curr_root->val);
            }

            if (curr_root->left) {
                t_que.push(curr_root->left);
            }
            if (curr_root->right) {
                t_que.push(curr_root->right);
            }
        }
        ret_stk.push(i_vec);
    }

    while (!ret_stk.empty()) {
        ret_vec.push_back(ret_stk.top());
        ret_stk.pop();
    }

    return ret_vec;
}
