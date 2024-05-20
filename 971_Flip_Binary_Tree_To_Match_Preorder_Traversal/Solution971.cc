#include <stack>
#include "Solution971.h"
using namespace std;

vector<int> Solution::flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    if (!root || voyage.empty())
        return vector<int> {-1};
    
    if (root->val != voyage[0])
        return vector<int> {-1};
    
    // preorder traverse
    stack<TreeNode*> tree_stk;
    tree_stk.push(root);
    int i=0;
    vector<int> i_vec;
    while (!tree_stk.empty() && i<voyage.size()) {
        TreeNode* temp = tree_stk.top();
        tree_stk.pop();
        if (temp->val != voyage[i]) {
            return vector<int> {-1};
        } else {
            if (i == voyage.size()-1) {
                return i_vec;
            } else {
                // leaf node then do nothing
                if (temp->left && temp->right) {
                    // two children nodes
                    if (temp->right->val == voyage[i+1]) {
                        // swap needed
                        tree_stk.push(temp->left);
                        tree_stk.push(temp->right);
                        i_vec.push_back(temp->val);
                    } else {
                        // no swap needed
                        tree_stk.push(temp->right);
                        tree_stk.push(temp->left);
                    }
                } else if (temp->left || temp->right){
                    // only one child
                    if (temp->right) {
                        tree_stk.push(temp->right);
                    } else if (temp->left) {
                        tree_stk.push(temp->left);
                    }
                }
            }
        }
        i++;
    }
    return i_vec;
}
