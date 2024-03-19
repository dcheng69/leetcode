#include <iostream>
#include <queue>
#include "Solution513.h"
using namespace std;

int Solution::findBottomLeftValue(TreeNode* root) {
    if (!root)  {
        cerr << "invalid input!" << endl;
        return -1;
    }

    queue<TreeNode*> t_que;
    t_que.push(root);
    int left_bottom_val = 0;
    while (!t_que.empty()) {
        int level_size = t_que.size();
        for (int i=0; i<level_size; i++) {
            TreeNode* tree_temp_p = t_que.front();
            if (0 == i) {
                left_bottom_val = tree_temp_p->val;
            }
            t_que.pop();
            if (tree_temp_p->left) {
                t_que.push(tree_temp_p->left);
            }
            if (tree_temp_p->right) {
                t_que.push(tree_temp_p->right);
            }
        }
    }

    return left_bottom_val;
}
