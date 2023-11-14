#include <iostream>
#include <string>
#include "Solution129.h"
#include "TreeNode.h"
#include "PrintX.h"
using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> s_vec{"4", "9", "0", "5", "1"};
    SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
    PrintTree(st.GetRootNodePointer());
    cout << s.sumNumbers(st.GetRootNodePointer()) << endl;
    return 0;
}
