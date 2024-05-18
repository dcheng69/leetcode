#include "Solution988.h"
using namespace std;

std::string Solution::smallestFromLeaf(TreeNode* root) {
    string ret = "";
    dfs(root, "", ret);
    return ret;
}

void Solution::dfs(TreeNode* root, string str, string &smallest) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        string new_str = static_cast<char>('a' + root->val) + str;
        if (smallest == "") {
            smallest = new_str;
        } else {
            smallest = smallest < new_str ? smallest : new_str;
            return;
        }
    }
    dfs(root->left, static_cast<char>('a' + root->val)+str, smallest);
    dfs(root->right, static_cast<char>('a' + root->val)+str, smallest);
    return;
}
