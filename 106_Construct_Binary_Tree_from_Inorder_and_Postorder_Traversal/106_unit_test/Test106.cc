#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution106.h"
#include "PrintX.h"
using namespace std;

TEST(Test106, CheckZeroNode) {
    Solution s;
    vector<int> inorder;
    vector<int> postorder;

    inorder.clear();
    postorder.clear();
    EXPECT_EQ(s.buildTree(inorder, postorder), nullptr);
}

TEST(Test106, CheckOneNode) {
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

TEST(Test106, CheckTwoNode) {
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

TEST(Test106, CheckThreeNode) {
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

TEST(Test106, CheckFourNode) {
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

TEST(Test106, CheckFiveNode) {
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

TEST(Test106, CheckSixNode) {
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

