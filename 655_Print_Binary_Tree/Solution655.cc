#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include "Solution655.h"
using namespace std;
#define SOLUTION_2

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

#ifdef SOLUTION_1
std::vector<std::vector<std::string>> Solution::printTree(TreeNode* root) {
    height = findTreeHeight(root);
    int m = height + 1;
    int n = pow(2, height+1) - 1;

    vector<vector<string>> str_vec_vec(m, vector<string>(n, ""));
    fillValueInTree(root, str_vec_vec, 0, (n-1)/2);
    return str_vec_vec;
}
#endif // !SOLUTION_1
#ifdef SOLUTION_2
/**
 * Use level-order Traversal to solve this problem non recursively
 *
 */
std::vector<std::vector<std::string>> Solution::printTree(TreeNode* root) {
    height = findTreeHeight(root);
    int row = height + 1;
    int col = pow(2, row) - 1;

    vector<vector<string>> str_vec_vec(row, vector<string>(col, ""));
    if (!root)
        return str_vec_vec;

    // first fill out the root node
    int curr_row = 0;
    int curr_col = (col-1)/2;
    str_vec_vec[curr_row][curr_col] = to_string(root->val);
    queue<pair<TreeNode*, int>> tree_col_pair_que;
    tree_col_pair_que.push(make_pair(root, curr_col));
    // perform a level order traversal while keeping the height variable
    while (!tree_col_pair_que.empty()) {
        int size = tree_col_pair_que.size();
        while (size--) {
            auto pair = tree_col_pair_que.front();
            tree_col_pair_que.pop();
            curr_col = pair.second;
            root = pair.first;
            str_vec_vec[curr_row][curr_col] = to_string(root->val);

            if (root->left) {
                tree_col_pair_que.push(make_pair(root->left, curr_col-pow(2, height-curr_row-1)));
            }
            if (root->right) {
                tree_col_pair_que.push(make_pair(root->right, curr_col+pow(2, height-curr_row-1)));
            }
        }
        curr_row++;
    }
    return str_vec_vec;
}
#endif // !SOLUTION_2
