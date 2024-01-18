#ifndef SOLUTION173_H_
#define SOLUTION173_H_
#include <vector>
#include <stack>
#include "TreeNode.h"

/**
 * Implement the class BSTIterator that represent a in-order traverse of a BST
 *
 *
 */

class BSTIterator {
    public:
        std::vector<int> inorderTraversal(TreeNode* root);

        /**
         * This is for inorderTraversal test usage
         */
        BSTIterator(): root(nullptr), currRoot(nullptr) {};

        BSTIterator(TreeNode* root);

        int next();

        bool hasNext();

        ~BSTIterator() {};

    private:
        TreeNode* root = nullptr;
        TreeNode* currRoot = nullptr;
        std::stack<TreeNode*> t_stk;
};

#endif
