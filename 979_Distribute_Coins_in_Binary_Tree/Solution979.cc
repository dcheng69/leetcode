#include <cmath>
#include <iostream>
#include "Solution979.h"
using namespace std;

int Solution::distributeCoins(TreeNode* root) {
    int ret = 0;
    traverse(root, ret);
    return ret;
}

/**
 * abstract the probelm to consider based on subtree move in out
 */
int Solution::traverse(TreeNode* root, int &moves) {
    if (!root)
        return 0;
    int l_balance = traverse(root->left, moves);
    int r_balance = traverse(root->right, moves);
    moves = moves + abs(l_balance) + abs(r_balance);
    return root->val - 1 + l_balance + r_balance;
}
