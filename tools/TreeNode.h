#ifndef TREENODE_H_
#define TREENODE_H_
#include <vector>
#include <string>

/**
 * @brief TreeNode is a binary tree node define by leetcode, normally used as params
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * @brief construct Binary Tree from given vector by layer
 *
 * @param vec vector contains TreeNode value by layer
 *
 * @return pointer to the head node
 */


/**
 * @brief Construct Binary Tree from given string vector by layer
 *
 * @param s_vec TreeNode values listed by layer, null_denotation represent no child
 * @param null_denotation representation of no child
 *
 * @return pointer to the root node
 */
struct TreeNode* ConstructTreeNode(const std::vector<std::string>& s_vec, const std::string null_denotation);


/**
 * @brief consturct a vector from a Tree by layer (for test)
 *
 * @param p_root
 *
 * @return vector<int> contains the layered traverse of the tree node
 */
std::vector<std::string> ConstructVector(TreeNode* p_root);


/**
 * @brief Smart pointer to hold the pointer
 * destructor function will be responsible for free elements
 */
class SmartTreeNode {
    public:
        SmartTreeNode() : p_root(nullptr) {}
        SmartTreeNode(TreeNode* p_tree_node) : p_root(p_tree_node) {}
        ~SmartTreeNode() {
            FreeTree(p_root);
            this->p_root = nullptr;
        };
        TreeNode* GetRootNodePointer() {return p_root;}
        TreeNode* RebindRootPointer(TreeNode* new_p_tree_node) {
            TreeNode* old_p_tree_node = p_root;
            this->p_root = new_p_tree_node;
            return old_p_tree_node;
        };
        static int FreeTree(TreeNode* p_tree_node);
    private:
        TreeNode* p_root;
};

#endif
