#include <iostream>
#include "Solution95.h"
#include "PrintX.h"
using namespace std;

vector<vector<string>> get2DResult(vector<TreeNode*> trees) {
    vector<vector<string>> ret;
    for (int i=0; i<trees.size(); i++) {
        TreeNode* root = trees[i];
        vector<string> s_vec = ConstructVector(root);
        ret.push_back(s_vec);
        Print("vector generated", s_vec);
    }
    return ret;
}

int main(int argc, char* argv[]) {
    Solution s;
    vector<TreeNode*> t_vec = s.generateTrees(3);
    for (int i=0; i<t_vec.size(); i++) {
        PrintTree(t_vec[i]);
        cout << endl;
    }

    vector<vector<string>> s_vec = get2DResult(t_vec);
    return 0;
}
