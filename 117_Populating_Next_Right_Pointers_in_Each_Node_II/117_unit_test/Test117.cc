#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution117.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

vector<int> allNextNodes(Node* p_node) {
    vector<int> i_vec;

    while (p_node) {
        i_vec.push_back(p_node->val);
        p_node = p_node->next;
    }

    return i_vec;
}

TEST(Test116, Check) {
    Solution s;
    Node* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    s.connect(p_root);
    EXPECT_EQ(p_root, nullptr);
}

TEST(Test116, CheckOneNode) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartNode* st = new SmartNode(ConstructNode(s_vec, "null"));
        PrintNode(st->GetRootNodePointer());
        s.connect(st->GetRootNodePointer());
        Node* p_node = st->GetRootNodePointer();
        EXPECT_THAT(allNextNodes(p_node), ElementsAreArray({0}));
        delete st;
    }
}

TEST(Test116, CheckThreeNodes) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartNode* st = new SmartNode(ConstructNode(s_vec, "null"));
        PrintNode(st->GetRootNodePointer());
        s.connect(st->GetRootNodePointer());
        Node* p_node = st->GetRootNodePointer();
        EXPECT_THAT(allNextNodes(p_node), ElementsAreArray({0}));
        EXPECT_THAT(allNextNodes(p_node->left), ElementsAreArray({1, 2}));
        delete st;
    }
}

TEST(Test116, CheckSevenNodes) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0",
                    "1", "2",
                    "3", "4", "null", "6"});
        SmartNode* st = new SmartNode(ConstructNode(s_vec, "null"));
        PrintNode(st->GetRootNodePointer());
        s.connect(st->GetRootNodePointer());
        Node* p_node = st->GetRootNodePointer();
        EXPECT_THAT(allNextNodes(p_node), ElementsAreArray({0}));
        EXPECT_THAT(allNextNodes(p_node->left), ElementsAreArray({1, 2}));
        EXPECT_THAT(allNextNodes(p_node->left->left), ElementsAreArray({3, 4, 6}));
        delete st;
    }
}
