#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include <string>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/**
 * @brief construct Binary  from given vector by layer
 *
 * @param vec vector contains Node value by layer
 *
 * @return pointer to the head node
 */


/**
 * @brief Construct Binary  from given string vector by layer
 *
 * @param s_vec Node values listed by layer, null_denotation represent no child
 * @param null_denotation representation of no child
 *
 * @return pointer to the root node
 */
struct Node* ConstructNode(const std::vector<std::string>& s_vec, const std::string null_denotation);


/**
 * @brief consturct a vector from a  by layer (for test)
 *
 * @param p_root
 *
 * @return vector<int> contains the layered traverse of the node
 */
std::vector<std::string> ConstructVector(Node* p_root);

/**
 * @brief return the max depth of the node using BSF
 *
 * @param node
 *
 * @return max depth in int
 */
int MaxNodeDepth(Node *root);

/**
 * @brief return the max value int he tree
 *
 * @param root
 *
 * @return max value of the tree, return 0 for nullptr
 */
int MaxNodeValue(Node *root);

/**
 * @brief Smart pointer to hold the pointer
 * destructor function will be responsible for free elements
 */
class SmartNode {
    public:
        SmartNode() : p_root(nullptr) {}
        SmartNode(Node* p_node) : p_root(p_node) {}
        ~SmartNode() {
            FreeNode(p_root);
            this->p_root = nullptr;
        };
        Node* GetRootNodePointer() {return p_root;}
        Node* RebindRootPointer(Node* new_p_node) {
            Node* old_p_node = p_root;
            this->p_root = new_p_node;
            return old_p_node;
        };
        static int FreeNode(Node* p_node);
    private:
        Node* p_root;
};
#endif
