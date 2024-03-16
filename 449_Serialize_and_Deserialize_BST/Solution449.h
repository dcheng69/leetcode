#ifndef SOLUTION449_H_
#define SOLUTION449_H_
#include <string>
#include <vector>
#include "TreeNode.h"

class Solution {
    public:
        // Encodes a tree to a single string.
        std::string serialize(TreeNode* root);

        // Decodes your encoded data to tree.
        TreeNode* deserialize(std::string data);

        // Code for Test
        std::vector<int> inorderTraversal(TreeNode* root);
        std::vector<int> postorderTraversal(TreeNode* root);
        TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);
};

#endif
