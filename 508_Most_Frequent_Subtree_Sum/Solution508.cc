#include <algorithm>
#include <map>
#include <stack>
#include "Solution508.h"
using namespace std;

/**
 * @brief This function is used to test the inorder Traversal non recursive code
 *
 * @param root
 *
 * @return 
 */
std::vector<int> Solution::inorderTraversal(TreeNode* root) {
    stack<TreeNode*> t_stk;
    vector<int> i_vec;

    if (!root) {
        return i_vec;
    }

    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        t_stk.pop();
        i_vec.push_back(root->val);
        if (root->right) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }

    return i_vec;
}

long long int Solution::calSubTreeSum(TreeNode* root) {
    long long int sum = 0;
    stack<TreeNode*> t_stk;

    if (!root) {
        return sum;
    }

    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        t_stk.pop();
        sum += root->val;
        if (root->right) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }

    return sum;
}

std::vector<int> Solution::findFrequentTreeSum(TreeNode* root) {
        vector<int> i_vec;
        stack<TreeNode*> t_stk;
        map<TreeNode*, int> hashSubTreeSum;
        map<int, int> subTreeSumPair;

        if (!root) {
            return i_vec;
        }

        while (root || !t_stk.empty()) {
            while (root) {
                t_stk.push(root);
                root = root->left;
            }

            root = t_stk.top();
            t_stk.pop();
            // Code to Calculate the subtree Sum
            long long int sum = 0;
            if (hashSubTreeSum.find(root) == hashSubTreeSum.end()) {
                sum = calSubTreeSum(root);
                hashSubTreeSum.insert({root, sum});
            } else {
                sum = hashSubTreeSum.find(root)->second;
            }
            // update value into the hash map
            if (subTreeSumPair.find(sum) == subTreeSumPair.end()) {
                // insear value to the hash map
                subTreeSumPair.insert({sum, 1});
            } else {
                // update the value of the current value
                subTreeSumPair.find(sum)->second++;
            }

            if (root->right) {
                root = root->right;
            } else {
                root = nullptr;
            }
        }

        // extract the result from the subTreeSumPair hashmap
        vector<pair<int, int>> tempVec(subTreeSumPair.begin(), subTreeSumPair.end());
        sort(tempVec.begin(), tempVec.end() , [](const auto& a, const auto& b) {
                return a.second > b.second;
                });
        // extract the results
        const int frq =  tempVec.begin()->second;
        for (int i=0; i<tempVec.size(); i++) {
            if (tempVec[i].second == frq)
                i_vec.push_back(tempVec[i].first);
            else
                break;
        }

        return i_vec;
}
