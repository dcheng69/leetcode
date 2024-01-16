#ifndef PRINTX_H_
#define PRINTX_H_
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "TreeNode.h"
#include "ListNode.h"
#include "Node.h"

template<typename T>
std::string PrintToString(const std::string name, const T& vec) {
    std::stringstream ss;
    if (vec.size() != 0) {
        ss << name << ":\t";
        for (auto const& n : vec)
            ss << n << ' ';
        ss << std::endl;
    }
    return ss.str();
}

template<typename T>
void Print(const std::string name, const T& vec) {
    std::cout << PrintToString(name, vec);
}


/**
 * @brief print tree node with appropriate inditetion recursively
 *
 * @param node pointer to the tree root
 */
void PrintTree(TreeNode* p_node);

/**
 * @brief print list node with appropriate inditetion recursively
 *
 * @param node pointer to the list head
 */
void PrintList(ListNode* p_node);

/**
 * @brief print tree node with appropriate inditetion recursively
 *
 * @param node pointer to the tree root
 */
void PrintNode(Node* p_node);
#endif
