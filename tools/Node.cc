#include <queue>
#include "Node.h"
#include "ErrorNo.h"
using namespace std;


struct Node* ConstructNode(const std::vector<std::string>& s_vec, const std::string null_denotation) {
    vector<Node*> node_vec;

    if (s_vec.size() == 0)
        return nullptr;
    else if(s_vec[0] == null_denotation)
        return nullptr;

    // calculate node structure from index
    // left child --> (2n+1)
    // right child --> (2n+2)
    // Construct the node_vec
    for(int i=0; i<s_vec.size(); i++) {
        Node* p_node = nullptr;
        if (s_vec[i] == null_denotation) {
            p_node = nullptr;
        } else {
            p_node = new Node(stoi(s_vec[i]));
        }
        node_vec.push_back(p_node);
    }

    for(int i=0; i<node_vec.size(); i++) {
        if (node_vec[i] == nullptr) {
            continue;
        }
        Node* p_root = node_vec[i];
        int left_index = 2*i+1, right_index = 2*i+2;

        if (left_index < node_vec.size()) {
            p_root->left = node_vec[left_index];
        } else {
            p_root->left = nullptr;
        }

        if (right_index < node_vec.size()) {
            p_root->right = node_vec[right_index];
        } else {
            p_root->right = nullptr;
        }
    }

    return node_vec[0];
}

std::vector<std::string> ConstructVector(Node* p_root) {
    // use queue to genereate layer traverse
    vector<string> s_vec;
    if (p_root == nullptr)
        return s_vec;
    s_vec.push_back(to_string(p_root->val));

    queue<Node*> node_que;
    node_que.push(p_root);

    int max_depth = MaxNodeDepth(p_root);
    // layer traverse
    for (int i=0; i<max_depth-1; ++i) {
        int level_size = node_que.size();
        for (int j=0; j<level_size; ++j) {
            Node* p_node = node_que.front();
            node_que.pop();
            if (p_node == nullptr) {
                // left and right are nullptr
                node_que.push(nullptr);
                node_que.push(nullptr);
                s_vec.push_back("null");
                s_vec.push_back("null");
                continue;
            }
            // push all its child to queue
            if (p_node->left != nullptr) {
                node_que.push(p_node->left);
                s_vec.push_back(to_string(p_node->left->val));
            } else {
                node_que.push(nullptr);
                s_vec.push_back("null");
            }
            if (p_node->right != nullptr) {
                node_que.push(p_node->right);
                s_vec.push_back(to_string(p_node->right->val));
            } else {
                node_que.push(nullptr);
                s_vec.push_back("null");
            }
        }
    }

    return s_vec;
}

int MaxNodeDepth(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    // find the max depth non recursively
    int max_depth = 0;
    queue<Node*> node_queue;
    node_queue.push(root);

    while (!node_queue.empty()) {
        int level_size = node_queue.size();
        for (int i=0; i<level_size; ++i) {
            Node* curr_root = node_queue.front();
            node_queue.pop();

            if (curr_root->left != nullptr) {
                node_queue.push(curr_root->left);
            }

            if(curr_root->right != nullptr) {
                node_queue.push(curr_root->right);
            }
        }
        max_depth++;
    }
    return max_depth;
}

int MaxNodeValue(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    // find the max depth non recursively
    int max_value= root->val;
    queue<Node*> node_queue;
    node_queue.push(root);

    while (!node_queue.empty()) {
        int level_size = node_queue.size();
        for (int i=0; i<level_size; ++i) {
            Node* curr_root = node_queue.front();
            node_queue.pop();

            if (curr_root->left != nullptr) {
                max_value = max_value>curr_root->left->val ? max_value : curr_root->left->val;
                node_queue.push(curr_root->left);
            }

            if(curr_root->right != nullptr) {
                max_value = max_value>curr_root->right->val ? max_value : curr_root->right->val;
                node_queue.push(curr_root->right);
            }
        }
    }
    return max_value;
}

int SmartNode::FreeNode(Node* p_node) {
    int ret = SUCCESS;
    queue<Node*> node_que;
    // free recursively
    if (p_node == nullptr)
        return ret;

    node_que.push(p_node);
    while(!node_que.empty()) {
        Node* p_root = node_que.front();
        node_que.pop();
        if (p_root->left != nullptr) {
            node_que.push(p_root->left);
        }
        if (p_root->right != nullptr) {
            node_que.push(p_root->right);
        }
        free(p_root);
        p_root = nullptr;
    }

    return ret;
}
