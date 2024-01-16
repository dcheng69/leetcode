#include <queue>
#include <iostream>
#include "Solution116.h"
using namespace std;

Node* Solution::connect(Node* root) {
    if (!root) {
        return root;
    }

    queue<Node*> n_que;
    n_que.push(root);
    Node* p_last_node = nullptr;
    while (!n_que.empty()) {
        int size = n_que.size();
        while (size--) {
            Node* p_node = n_que.front();
            n_que.pop();

            if (p_last_node) {
                p_last_node->next = p_node;
            }
            p_last_node = p_node;

            if (p_node->left) {
                n_que.push(p_node->left);
            }

            if (p_node->right) {
                n_que.push(p_node->right);
            }
        }
        p_last_node->next = nullptr;
        p_last_node = nullptr;
    }

    return root;
}
