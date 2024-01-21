#include <iostream>
#include "Solution236.h"
using namespace std;

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q)
        return nullptr;

    // locate the sequence from root to p
    vector<TreeNode*> root_to_p;
    vector<TreeNode*> root_to_q;

    vector<TreeNode*> t_stk;
    TreeNode* last_visited = nullptr;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push_back(root);
            if (root == p)
                root_to_p.assign(t_stk.begin(), t_stk.end());
            if (root == q)
                root_to_q.assign(t_stk.begin(), t_stk.end());
            root = root->left;
        }

        root = t_stk.back();
        if (root->right && last_visited != root->right) {
            root = root->right; // this node will be pushed by next loop
        } else {
            // leaf or visited
            last_visited = root;
#ifdef DEBUG
            Print("visited path:",t_stk);
            cout << root->val << endl;
#endif
            t_stk.pop_back();
            root = nullptr;
        }
    }

#ifdef DEBUG
    Print("from root to p",root_to_p);
    Print("from root to q",root_to_q);
    cout << endl << endl;
#endif

    // find the last one with same address int he root_to_q and root_to_q
    TreeNode* ret = nullptr;
    int i=0;
    while (i<root_to_p.size() && i<root_to_q.size()) {
        if (root_to_p[i] == root_to_q[i]) {
            ret = root_to_p[i];
        } else {
            break;
        }
        i++;
    }

    return ret;
}
