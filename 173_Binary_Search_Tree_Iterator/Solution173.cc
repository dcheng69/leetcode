#include <iostream>
#include "Solution173.h"
#include "PrintX.h"
using namespace std;


vector<int> BSTIterator::inorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (!root) {
        return i_vec;
    }
#if 0

    stack<TreeNode*> t_stk;
    TreeNode* curr = root;
    while (curr || !t_stk.empty()) {
        while (curr) {
            t_stk.push(curr);
            curr = curr->left;
        }

        curr = t_stk.top();
        t_stk.pop();
        i_vec.push_back(curr->val);
        curr = curr->right;
    }
#else
    BSTIterator it(root);
    while (it.hasNext()) {
        i_vec.push_back(it.next());
    }
#endif
    return i_vec;
}

BSTIterator::BSTIterator(TreeNode* root): root(root), currRoot(root) {
    // keep stak empty
    while (!this->t_stk.empty()) {
        // keep the stack empty
        this->t_stk.pop();
    }
}

int BSTIterator::next() {
    int ret;
    if (this->hasNext()) {
        while (this->currRoot) {
            this->t_stk.push(this->currRoot);
            this->currRoot = this->currRoot->left;
        }

        this->currRoot = this->t_stk.top();
        this->t_stk.pop();
        ret = this->currRoot->val;
        this->currRoot = this->currRoot->right;
    }
    return ret;
}

bool BSTIterator::hasNext() {
    return (currRoot || !this->t_stk.empty());
}
