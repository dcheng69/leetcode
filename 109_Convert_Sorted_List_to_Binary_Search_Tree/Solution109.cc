#include <stack>
#include <iostream>
#include "Solution109.h"
#include "PrintX.h"
using namespace std;

TreeNode* Solution::sortedListToBST(ListNode* head) {
    if (!head)
        return NULL;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    // fast and slorew pointer to find the mid node of the List
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // now the slow is the root node for the List
    TreeNode* root = new TreeNode(slow->val);

    // check if the list only has one element
    if (slow == head)
        return root;

    // build the left and right sub tree
    prev->next = NULL; // split the linked list into two halves
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}
