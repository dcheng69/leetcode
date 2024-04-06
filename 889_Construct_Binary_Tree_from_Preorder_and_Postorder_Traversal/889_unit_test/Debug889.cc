#include "PrintX.h"
#include "Solution889.h"
using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> preorder;
    vector<int> postorder;

    {
        preorder.clear();
        preorder.assign({1,2,4,5,3,6,7});
        postorder.clear();
        postorder.assign({4,5,2,6,7,3,1});
        PrintTree(s.constructFromPrePost(preorder, postorder));
    }

    return 0;
}
