#include <queue>
#include "Solution958.h"
using namespace std;

bool Solution::isCompleteTree(TreeNode* root) {
    if (!root) {
        // this should not happened
        return false;
    }

    bool ret = false;
    // perform level order traverse
    queue<TreeNode*> tree_que;
    tree_que.push(root);
    while (!tree_que.empty()) {
        TreeNode* temp = tree_que.front();
        tree_que.pop();
        if (!temp) {
            // the rest of the queue should be all nullptr otherwise false
            while(!tree_que.empty()) {
                temp = tree_que.front();
                tree_que.pop();
                if (temp) {
                    return false;
                } else {
                    continue;
                }
            }
            ret = true;
            break;
        }
        tree_que.push(temp->left);
        tree_que.push(temp->right);
    }
    return ret;
}
