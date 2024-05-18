#include "Solution979.h"
#include "TreeNode.h"
using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> s_vec;
    s_vec.assign({"0", "2", "3", "0", "0", "null", "null", "1"});
    SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
    TreeNode* root = st.GetRootNodePointer();
    s.distributeCoins(root);
    return 0;
}
