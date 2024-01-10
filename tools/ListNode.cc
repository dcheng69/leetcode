#include "ListNode.h"
using namespace std;

struct ListNode* ConstructListNode(const vector<int>& i_vec) {
    struct ListNode* head = nullptr;

    if (i_vec.size() == 0)
        return head;

    // construct ListNode one by one from rear to haed
    ListNode* prev_node = nullptr;
    for (int i=i_vec.size()-1; i>=0; i--){
        ListNode* node = new ListNode(i_vec[i], prev_node);
        prev_node = node;
    }
    head = prev_node;

    return head;
}

vector<int> GetVectorFromListNode(ListNode* p_node) {
    vector<int> i_vec;
    while (p_node) {
        i_vec.push_back(p_node->val);
        p_node = p_node->next;
    }

    return i_vec;
}
