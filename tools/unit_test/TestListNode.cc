#include <vector>
#include <stack>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ListNode.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(TestTreeNode, TestConstructVectorFromList) {
    ListNode* p_node = nullptr;

    // null input
    ASSERT_EQ(GetVectorFromListNode(p_node).size(), 0);

    // one input
    p_node = new ListNode(1);
    ASSERT_THAT(GetVectorFromListNode(p_node), ElementsAreArray({1}));

    // two inputs
    p_node->next = new ListNode(2);
    ASSERT_THAT(GetVectorFromListNode(p_node), ElementsAreArray({1, 2}));

    // delete the elements created
    ListNode* p_next = nullptr;
    while (p_node) {
        p_next = p_node->next;
        delete(p_node);
        p_node = p_next;
    }
    p_next = nullptr;
}

TEST(TestTreeNode, TestConstructListNode) {
    ListNode* p_node = nullptr;
    vector<int> i_vec;
    // test null input vector
    ASSERT_EQ(ConstructListNode(i_vec), nullptr);

    // test one input
    i_vec.clear();
    i_vec = {1};
    p_node = ConstructListNode(i_vec);
    ASSERT_THAT(GetVectorFromListNode(p_node), ElementsAreArray({1}));
    SmartListNode::FreeList(p_node);

    // test two input
    i_vec.clear();
    i_vec = {1, 2};
    p_node = ConstructListNode(i_vec);
    ASSERT_THAT(GetVectorFromListNode(p_node), ElementsAreArray({1, 2}));
    SmartListNode::FreeList(p_node);
}
