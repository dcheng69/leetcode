#include <algorithm>
#include <cmath>
#include <string>
#include "Solution655.h"
using namespace std;

int Solution::findTreeHeight(TreeNode* root) {
    if (!root)
        return -1;
    return 1 + max(findTreeHeight(root->left), findTreeHeight(root->right));
}

void Solution::fillValueInTree(TreeNode* root, std::vector<std::vector<std::string>> &str_vec_vec, int row, int col) {
    if (!root)
        return;

    str_vec_vec[row][col] = to_string(root->val);
    int left_col = col - pow(2, height-row-1);
    int right_col = col + pow(2, height-row-1);
    fillValueInTree(root->left, str_vec_vec, row + 1, left_col);
    fillValueInTree(root->right, str_vec_vec, row + 1, right_col);
}

std::vector<std::vector<std::string>> Solution::printTree(TreeNode* root) {
    height = findTreeHeight(root);
    int m = height + 1;
    int n = pow(2, height+1) - 1;

    vector<vector<string>> str_vec_vec(m, vector<string>(n, ""));
    fillValueInTree(root, str_vec_vec, 0, (n-1)/2);
    return str_vec_vec;
}
