#include <iostream>
#include <stack>
#include "Solution112.h"
using namespace std;
#define SOLUTION_2

#ifdef SOLUTION_1
bool Solution::hasPathSum(TreeNode* root, int targetSum) {
    bool ret = false;
    long long sum = 0;
    if (!root) {
        return ret;
    }

    stack<TreeNode*> t_stk;
    t_stk.push(root);
    sum += root->val;
    TreeNode* last_visited = nullptr;

    while (!t_stk.empty()) {
        root = t_stk.top();
        if (last_visited && root->right == last_visited) {
            // visited pop
            last_visited = t_stk.top();
            t_stk.pop();
            sum -= last_visited->val;
            continue;
        }

        if (root->left && root->left != last_visited) {
            t_stk.push(root->left);
            sum += root->left->val;
            continue;
        }

        if (root->right) {
            t_stk.push(root->right);
            sum += root->right->val;
            continue;
        }

        // leaf node and visited node
        last_visited = root;
        if (!root->left && !root->right && sum == targetSum) {
            // leaf
            ret = true;
            break;
        }
        sum -= t_stk.top()->val;
        t_stk.pop();
    }

    return ret;
}
#endif

#ifdef SOLUTION_2
bool Solution::hasPathSum(TreeNode* root, int targetSum) {
    bool ret = false;
    if (!root)
        return ret;

    stack<TreeNode*> t_stk;
    long long sum = 0;
    TreeNode* last_visited = nullptr;

    t_stk.push(root);
    sum+=root->val;
    while(!t_stk.empty()) {
        root = t_stk.top();
        if (last_visited && last_visited == root->right) {
            last_visited = root;
            cout << "last_visited 1:" << last_visited->val << endl;
            sum-=t_stk.top()->val;
            t_stk.pop();
            continue;
        }

        while (root->left && root->left != last_visited) {
            t_stk.push(root->left);
            sum+=root->left->val;
            root = root->left;
        }

        if (root->right && root->right != last_visited) {
            t_stk.push(root->right);
            sum+=root->right->val;
            continue;
        }

        if (!root->left && !root->right && sum == targetSum) {
            ret = true;
            break;
        }
        last_visited = root;
        cout << "last_visited 2:" << last_visited->val << endl;
        sum-=t_stk.top()->val;
        t_stk.pop();
    }

    return ret;
}
#endif
