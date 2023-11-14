#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include "Solution129.h"
#include "PrintX.h"
using namespace std;

int getNumberFromVec(vector<int> &i_vec) {
    int ret = 0;
    for (int i=i_vec.size()-1, j=0; i>=0; i--, j++) {
        int digit = pow(10, j);
        ret += i_vec[i] * digit;
    }

    return ret;
}

int Solution::sumNumbers(TreeNode* root) {
    int sum = 0;
    if (root == nullptr)
        return sum;

    stack<TreeNode *> tree_stk;
    vector<int> i_vec;
    TreeNode* prev = nullptr;

    while (!tree_stk.empty() || root) {
        while (root) {
            tree_stk.push(root);
            i_vec.push_back(root->val);
            root = root->left;
        }

        root = tree_stk.top();
        if (root->right && prev != root->right) {
            root = root->right;
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                // Print("i_vec:", i_vec);
                sum += getNumberFromVec(i_vec);
            }
            prev = root;
            tree_stk.pop();
            i_vec.pop_back();
            root = nullptr;
        }
    }

    return sum;
}
