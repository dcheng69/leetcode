#include <string>
#include "Solution863.h"
#include "TreeNode.h"
using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> s_vec;
    s_vec.assign({"3",
            "5", "1",
            "6", "2", "0", "8",
            "null", "null", "7", "4"});
    SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
    TreeNode* root = st.GetRootNodePointer();
    TreeNode* target = root->left;
    s.distanceK(root, target, 2);

    s_vec.clear();
    s_vec.assign({"1"});
    SmartTreeNode st_1(ConstructTreeNode(s_vec, "null"));
    root = st_1.GetRootNodePointer();
    target = root;
    s.distanceK(root, target, 3);

    return 0;
}
