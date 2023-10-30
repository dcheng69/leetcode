#include <string>
#include <iostream>
#include "TreeNode.h"
#include "PrintX.h"
using namespace std;

int main(int argc, char* argv[]) {
    vector<string> s_vec{"0", "1"};
    SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
    TreeNode * p_root = st.GetRootNodePointer();
    vector<string> ret = ConstructVector(p_root);
    Print("result: ", ret);
    return 0;
}
