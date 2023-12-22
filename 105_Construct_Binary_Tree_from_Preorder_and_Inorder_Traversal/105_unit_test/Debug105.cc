#include <iostream>
#include "Solution105.h"
#include "PrintX.h"
using namespace std;

int main(int argc, char* argv[]) {
    cout << "Enjoy debuging!" << endl;
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
        PrintTree(st_compare.GetRootNodePointer());
        SmartTreeNode st_ret(s.buildTree(preorder, inorder));
        PrintTree(st_ret.GetRootNodePointer());
    }
    return 0;
}
