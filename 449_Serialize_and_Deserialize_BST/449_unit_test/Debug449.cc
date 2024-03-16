#include <iostream>
#include "PrintX.h"
#include "Solution449.h"
using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> inorder;
    vector<int> postorder;
    vector<string> s_vec;

    // only one root node with value of 0
    inorder.clear();
    inorder = {1, 0};
    postorder.clear();
    postorder = {1, 0};
    s_vec.clear();
    s_vec = {"0", "1"};
    TreeNode* p_comapre_root = ConstructTreeNode(s_vec, "null");
    TreeNode* p_ret_root = s.deserialize(s.serialize(p_comapre_root));
    Print("p_ret_root", ConstructVector(p_ret_root));
    Print("p_cmp_root", ConstructVector(p_comapre_root));
    return 0;
}
