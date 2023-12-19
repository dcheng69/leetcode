#include <iostream>
#include "Solution106.h"
#include "PrintX.h"
using namespace std;

int main(int argc, char* argv[]) {
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
        inorder = {4, 0, 2, 3, 1};
        postorder.clear();
        postorder = {4, 3, 2, 1, 0};
        s_vec.clear();
        s_vec = {"0", "4", "1", "null", "null", "2", "null", "null", "null", "null", "null", "null", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        PrintTree(st_compare.GetRootNodePointer());
        cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
        SmartTreeNode st_ret(s.buildTree(inorder, postorder));
        PrintTree(st_ret.GetRootNodePointer());
    }
    return 0;
}
