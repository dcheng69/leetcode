#include <iostream>
#include <vector>
#include "Solution145.h"
#include "PrintX.h"
using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> s_vec{"3","2", "4", "null", "null", "1"};
    SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
    PrintTree(st->GetRootNodePointer());
    TreeNode* p_root = st->GetRootNodePointer();
    vector<int> ret = s.postorderTraversal(p_root);
    Print("ret: ", ret);
    return 0;
}
