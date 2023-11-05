#include <iostream>
#include <vector>
#include "Solution144.h"
#include "PrintX.h"
using namespace std;

int main(int argc, char* argv[]) {
    vector<string> s_vec{"0", "null", "1", "null", "null", "null", "2"};
    SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
    PrintTree(st.GetRootNodePointer());
    cout << "Enjoy debuging!" << endl;
    return 0;
}
