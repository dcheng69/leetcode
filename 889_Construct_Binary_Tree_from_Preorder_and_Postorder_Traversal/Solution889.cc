#include "Solution889.h"
#include <algorithm>
using namespace std;

TreeNode* Solution::constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    if (preorder.size() <= 0 || postorder.size() <= 0 || preorder.size() != postorder.size())
        return nullptr;

    TreeNode* root = new TreeNode(*(preorder.begin()));
    if (preorder.size() == 1)
        return root;
    
    // construct two subVec and then recursively solve this problem
    auto left_pre_ir = preorder.begin() + 1;
    auto left_post_ir = postorder.begin();
    auto temp_ir = find(postorder.begin(), postorder.end(), *left_pre_ir);
    int length_left = (temp_ir - postorder.begin() + 1);

    auto right_pre_ir = left_pre_ir + length_left;
    auto right_post_ir = left_post_ir + length_left;
    int length_right = (postorder.end() -1 - temp_ir -1);

    auto left_pre = subVec(preorder, left_pre_ir, length_left);
    auto left_post = subVec(postorder, left_post_ir, length_left);
    if (preorder.begin() + 1 == postorder.end() - 1) {
        root->left = constructFromPrePost(left_pre, left_post);
        return root;
    }
    auto right_pre = subVec(preorder, right_pre_ir, length_right);
    auto right_post = subVec(postorder, right_post_ir, length_right);
    root->left = constructFromPrePost(left_pre, left_post);
    root->right = constructFromPrePost(right_pre, right_post);
    return root;
}

vector<int> Solution::subVec(vector<int>& i_vec, vector<int>::iterator start, unsigned int count) {
    vector<int> ret_vec;
    if (count < 1)
        return ret_vec;
    
    while (count-- && start != i_vec.end()) {
        ret_vec.push_back(*start++);
    }
    return ret_vec;
}
