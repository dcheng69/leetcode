#ifndef LISTNODE_H_
#define LISTNODE_H_
#include <vector>
/**
 * @brief ListNode is a singly-linked list defined by leetcode, normally used as params
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @brief Construct List with given vector
 *
 * @param i_vec vectors contains list elements
 *
 * @return pointer to the head element
 */
struct ListNode* ConstructListNode(const std::vector<int>& i_vec);

/**
 * @brief Construct vector with given list head
 *
 * @param p_node: the head of the list
 *
 * @return vector contains the same element with the same sequence of the list
 */
std::vector<int> GetVectorFromListNode(ListNode* p_node);

/**
 * @brief Smart pointer to hold the pointer
 * destructor function will be responsible for free elements
 */
class SmartListNode {
    public:
        SmartListNode() : p_root(nullptr) {}
        SmartListNode(ListNode* p_list_node) : p_root(p_list_node) {}
        ~SmartListNode() {
            FreeList(p_root);
            this->p_root = nullptr;
        };
        ListNode* GetRootNodePointer() {return p_root;}
        ListNode* RebindRootPointer(ListNode* new_p_list_node) {
            ListNode* old_p_list_node = p_root;
            this->p_root = new_p_list_node;
            return old_p_list_node;
        };
        static int FreeList(ListNode* p_list_node) {
            ListNode* p_next = nullptr;
            while (p_list_node) {
                p_next = p_list_node->next;
                delete(p_list_node);
                p_list_node = p_next;
            }
            p_next = nullptr;

            return 0;
        };
    private:
        ListNode* p_root;
};
#endif
