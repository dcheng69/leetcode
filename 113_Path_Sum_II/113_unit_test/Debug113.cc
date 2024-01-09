#include <iostream>
#include "Solution113.h"
#include "PrintX.h"
using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> s_vec;
    // Four Node
    {
        /**
         *             0
         *       null      1
         *              2    null
         *          null   3
         **/
        s_vec.clear();
        s_vec = {"5",
            "4", "8",
        "11", "null", "13", "4",
        "7", "2", "null", "null", "null", "null", "5", "1"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        PrintTree(st_compare.GetRootNodePointer());
        cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
        s.pathSum(st_compare.GetRootNodePointer(), 22);
    }
    return 0;
}
