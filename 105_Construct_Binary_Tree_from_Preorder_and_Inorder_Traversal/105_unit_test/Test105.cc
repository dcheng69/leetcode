#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution105.h"
#include "PrintX.h"
using namespace std;

TEST(Test105, CheckZeroNode) {
    Solution s;
    vector<int> inorder;
    vector<int> preorder;

    inorder.clear();
    preorder.clear();
    EXPECT_EQ(s.buildTree(preorder, inorder), nullptr);
}

TEST(Test105, CheckOneNode) {
    Solution s;
    vector<int> inorder;
    vector<int> preorder;
    vector<string> s_vec;

    // only one root node with value of 0
    inorder.clear();
    inorder = {0};
    preorder.clear();
    preorder = {0};
    s_vec.clear();
    s_vec = {"0"};
    TreeNode* p_comapre_root = ConstructTreeNode(s_vec, "null");
    TreeNode* p_ret_root = s.buildTree(preorder, inorder);
    EXPECT_EQ(ConstructVector(p_ret_root), ConstructVector(p_comapre_root));
}

TEST(Test105, CheckTwoNode) {
    Solution s;
    vector<int> inorder;
    vector<int> preorder;
    vector<string> s_vec;

    // two node tree
    {
        /**
         *    0
         *  1   null
         **/
        inorder.clear();
        inorder = {1, 0};
        preorder.clear();
        preorder = {0, 1};
        s_vec.clear();
        s_vec = {"0", "1"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }

    {
        /**
         *      0
         *  null   1
         **/
        inorder.clear();
        inorder = {0, 1};
        preorder.clear();
        preorder = {0, 1};
        s_vec.clear();
        s_vec = {"0", "null", "1"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }

}

TEST(Test105, CheckThreeNode) {
    Solution s;
    vector<int> inorder;
    vector<int> preorder;
    vector<string> s_vec;

    // Three Node
    {
        /**
         *    0
         *  1   2
         **/
        inorder.clear();
        inorder = {1, 0, 2};
        preorder.clear();
        preorder = {0, 1, 2};
        s_vec.clear();
        s_vec = {"0", "1", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
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
        preorder.clear();
        preorder = {0, 1, 2};
        s_vec.clear();
        s_vec = {"0", "1", "null", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
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
        preorder.clear();
        preorder = {0, 1, 2};
        s_vec.clear();
        s_vec = {"0", "1", "null", "null", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
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
        preorder.clear();
        preorder = {0, 1, 2};
        s_vec.clear();
        s_vec = {"0", "null", "1", "null", "null", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
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
        preorder.clear();
        preorder = {0, 1, 2};
        s_vec.clear();
        s_vec = {"0", "null", "1", "null", "null", "null", "2"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }
}

TEST(Test105, CheckFourNode) {
    Solution s;
    vector<int> inorder;
    vector<int> preorder;
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
        preorder.clear();
        preorder = {0, 1, 2, 3};
        s_vec.clear();
        s_vec = {"0", \
            "null", "1", \
        "null", "null", "2", "null", \
    "null", "null", "null", "null", "null", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        PrintTree(st_compare.GetRootNodePointer());
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }
}


TEST(Test105, CheckFiveNode) {
    Solution s;
    vector<int> inorder;
    vector<int> preorder;
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
        preorder.clear();
        preorder = {0, 4, 1, 2, 3};
        s_vec.clear();
        s_vec = {"0", "4", "1", "null", "null", "2", "null", "null", "null", "null", "null", "null", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }
}

TEST(Test105, CheckSixNode) {
    Solution s;
    vector<int> inorder;
    vector<int> preorder;
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
        preorder.clear();
        preorder = {0, 4, 5, 1, 2, 3};
        s_vec.clear();
        s_vec = {"0", "4", "1", "null", "5", "2", "null", "null", "null", "null", "null", "null", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
        EXPECT_EQ(ConstructVector(st_ret.GetRootNodePointer()), ConstructVector(st_compare.GetRootNodePointer()));
    }
}
