#include <algorithm>
#include <queue>
#include <strings.h>
#include <utility>
#include "Solution662.h"
using namespace std;

int Solution::widthOfBinaryTree(TreeNode* root) {
    if (!root)
        return -1;

    int max_width = 0;
    queue<pair<TreeNode*, int>> t_i_que;
    t_i_que.push(make_pair(root, 0));
    while (!t_i_que.empty()) {
        int size = t_i_que.size();
        long long left_most_index, right_most_index;

        for (int i=0; i<size; i++) {
            pair<TreeNode*, int> t_i_pair = t_i_que.front();
            t_i_que.pop();
            TreeNode* temp_p = t_i_pair.first;
            long long index = t_i_pair.second;

            if (temp_p->left)
                t_i_que.push(make_pair(temp_p->left, index*2+1));
            if (temp_p->right)
                t_i_que.push(make_pair(temp_p->right, index*2+2));

            if (i==0)
                left_most_index = index;
            if (i==size-1)
                right_most_index = index;
        }
        max_width = max(max_width, static_cast<int>(right_most_index-left_most_index+1));
    }
    return  max_width;
}
