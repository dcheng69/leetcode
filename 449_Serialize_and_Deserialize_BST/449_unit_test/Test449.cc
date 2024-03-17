#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution449.h"
#include "TreeNode.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test449, CheckSerialZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    {
        EXPECT_THAT(s.serialize(p_root), "");
    }
}

TEST(Test449, CheckSerialOneNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        st.GetRootNodePointer();
        EXPECT_THAT(s.serialize(st.GetRootNodePointer()), "0$0");
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckSerialTwoNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        st.GetRootNodePointer();
        EXPECT_THAT(s.serialize(st.GetRootNodePointer()), "1,0$1,0");
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    {
        EXPECT_EQ(s.inorderTraversal(p_root).size(), 0);
    }
}

TEST(Test449, CheckInorderOneNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderTwoNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,0}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0,1}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderThreeNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,0,2}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({2,1,0}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderFourNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,3,0,2}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderMultipleNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"15",
                "null", "20",
            "null", "null", "18", "30",
    "null", "null","null", "null", "16", "19"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({15,16,18,19,20,30}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckPostOneNode) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({0}));
        delete st;
    }
}

TEST(Test449, CheckPostTwoNode) {
    Solution s;
    vector<string> s_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0}));
        delete st;
    }
}

TEST(Test449, CheckPostThreeNode) {
    Solution s;
    vector<string> s_vec;

    // test three node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 2, 0}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({2, 1, 0}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1", "null", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({2, 1, 0}));
        delete st;
    }
}

TEST(Test449, CheckPostFourNode) {
    Solution s;
    vector<string> s_vec;

    // test four node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({3, 1, 2, 0}));
        delete st;
    }
    // test four node
    {
        s_vec.clear();
        s_vec.assign({"3","2", "4", "null", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({2, 1, 4, 3}));
        delete st;
    }
}

TEST(Test449, CheckBuildTreeZeroNode) {
    Solution s;
    vector<int> inorder;
    vector<int> preorder;

    inorder.clear();
    preorder.clear();
    EXPECT_EQ(s.buildTree(preorder, inorder), nullptr);
}

TEST(Test449, CheckBuildTreeOneNode) {
    Solution s;
    vector<int> inorder;
    vector<int> postorder;
    vector<string> s_vec;

    // only one root node with value of 0
    inorder.clear();
    inorder = {0};
    postorder.clear();
    postorder = {0};
    s_vec.clear();
    s_vec = {"0"};
    TreeNode* p_comapre_root = ConstructTreeNode(s_vec, "null");
    TreeNode* p_ret_root = s.buildTree(inorder, postorder);
    EXPECT_EQ(ConstructVector(p_ret_root), ConstructVector(p_comapre_root));
}

TEST(Test449, CheckBuildTreeTwoNode) {
    Solution s;
    vector<int> inorder;
    vector<int> postorder;
    vector<string> s_vec;

    // two node tree
    {
        /**
         *    0
         *  1   null
         **/
        inorder.clear();
        inorder = {1, 0};
        postorder.clear();
        postorder = {1, 0};
        s_vec.clear();
        s_vec = {"0", "1"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }

    {
        /**
         *      0
         *  null   1
         **/
        inorder.clear();
        inorder = {0, 1};
        postorder.clear();
        postorder = {1, 0};
        s_vec.clear();
        s_vec = {"0", "null", "1"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }

}

TEST(Test449, CheckBuildTreeThreeNode) {
    Solution s;
    vector<int> inorder;
    vector<int> postorder;
    vector<string> s_vec;

    // Three Node
    {
        /**
         *    0
         *  1   2
         **/
        inorder.clear();
        inorder = {1, 0, 2};
        postorder.clear();
        postorder = {1, 2, 0};
        s_vec.clear();
        s_vec = {"0", "1", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }

    {
        /**
         *        0
         *      1   null
         *   2
         **/
        inorder.clear();
        inorder = {2, 1, 0};
        postorder.clear();
        postorder = {2, 1, 0};
        s_vec.clear();
        s_vec = {"0", "1", "null", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }

    {
        /**
         *             0
         *           1   null
         *      null    2
         **/
        inorder.clear();
        inorder = {1, 2, 0};
        postorder.clear();
        postorder = {2, 1, 0};
        s_vec.clear();
        s_vec = {"0", "1", "null", "null", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }

    {
        /**
         *             0
         *       null      1
         *               2   null
         **/
        inorder.clear();
        inorder = {0, 2, 1};
        postorder.clear();
        postorder = {2, 1, 0};
        s_vec.clear();
        s_vec = {"0", "null", "1", "null", "null", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }

    {
        /**
         *             0
         *       null      1
         *                     2
         **/
        inorder.clear();
        inorder = {0, 1, 2};
        postorder.clear();
        postorder = {2, 1, 0};
        s_vec.clear();
        s_vec = {"0", "null", "1", "null", "null", "null", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }
}

TEST(Test449, CheckBuildTreeFourNode) {
    Solution s;
    vector<int> inorder;
    vector<int> postorder;
    vector<string> s_vec;

    // Four Node
    {
        /**
         *             0
         *       null      1
         *              2    null
         *          null   3
         **/
        inorder.clear();
        inorder = {0, 2, 3, 1};
        postorder.clear();
        postorder = {3, 2, 1, 0};
        s_vec.clear();
        s_vec = {"0", \
            "null", "1", \
        "null", "null", "2", "null", \
    "null", "null", "null", "null", "null", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        PrintTree(st_compare.GetRootNodePointer());
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }
}

TEST(Test449, CheckBuildTreeFiveeNode) {
    Solution s;
    vector<int> inorder;
    vector<int> postorder;
    vector<string> s_vec;

    // Five Node
    {
        /**
         *             0
         *        4        1
         *              2    null
         *          null   3
         **/
        inorder.clear();
        inorder = {4, 0, 2, 3, 1};
        postorder.clear();
        postorder = {4, 3, 2, 1, 0};
        s_vec.clear();
        s_vec = {"0", "4", "1", "null", "null", "2", "null", "null", "null", "null", "null", "null", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }
}

TEST(Test449, CheckBuildTreeSixNode) {
    Solution s;
    vector<int> inorder;
    vector<int> postorder;
    vector<string> s_vec;

    // Six Node
    {
        /**
         *             0
         *        4        1
         *          5   2    null
         *          null   3
         **/
        inorder.clear();
        inorder = {4, 5, 0, 2, 3, 1};
        postorder.clear();
        postorder = {5, 4, 3, 2, 1, 0};
        s_vec.clear();
        s_vec = {"0", "4", "1", "null", "5", "2", "null", "null", "null", "null", "null", "null", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }
}
