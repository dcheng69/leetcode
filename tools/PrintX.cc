#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
#include "PrintX.h"
using namespace std;

void PrintTree(TreeNode* p_node) {
    if (p_node == nullptr) {
        // do nothing and return
        return;
    }

    queue<TreeNode*> node_queue;
    node_queue.push(p_node);  // for layer traverse
    queue<string> s_queue;  // saving each layer's tree node string
    s_queue.push(to_string(p_node->val));

    // find the max depth of the tree first
    int max_depth = MaxTreeDepth(p_node);
    // cout << "max_depth: " << max_depth << endl;
    // calculate the max digit for inditation
    int max_value = MaxTreeValue(p_node);
    // cout << "max_value: " << max_value << endl;
    int max_digit = 0;
    while (max_value != 0) {
        max_digit++;
        max_value /= 10;
    }

    int curr_depth = 1;
    // calculate how many spaces should be in the last row, imagine a width of a matrix
    int max_space_eacho_row = pow(2, max_depth-1) * max_digit * 2 + max_digit;
    for (int l=0; l<max_depth; ++l) {
        // elements number for current row
        int current_elements_in_row = pow(2, curr_depth-1);
        // calculate the spaces each blank  ==> spaces left divided by number of blanks
        int spaces_for_each_blank = (max_space_eacho_row-current_elements_in_row*max_digit)/(pow(2, curr_depth-1) + 1);

        // elements number for each level
        int level_size = s_queue.size();
        for (int i=0; i<level_size; ++i) {
            string s = s_queue.front();
            s_queue.pop();

            // output the strings stored in the s_queue represents each layers of elements
            for (int j=0; j<spaces_for_each_blank; ++j) {
                cout << " ";
            }
            cout << setw(max_digit) << s;
        }
        cout << endl;

        // prepare for next layer of traverse
        level_size = node_queue.size();
        for (int i=0; i<level_size; ++i) {
            TreeNode* p_curr_node = node_queue.front();
            node_queue.pop();

            if (p_curr_node == nullptr) {
                // generate left right null child for counting
                node_queue.push(nullptr);
                node_queue.push(nullptr);
                // push null string to the s_queue
                s_queue.push(" ");
                s_queue.push(" ");
                continue;
            }

            if (p_curr_node->left != nullptr) {
                node_queue.push(p_curr_node->left);
                s_queue.push(to_string(p_curr_node->left->val));
            } else {
                node_queue.push(nullptr);
                s_queue.push(" ");
            }

            if (p_curr_node->right != nullptr) {
                node_queue.push(p_curr_node->right);
                s_queue.push(to_string(p_curr_node->right->val));
            } else {
                node_queue.push(nullptr);
                s_queue.push(" ");
            }
        }
        curr_depth++;
    }
}

void PrintList(ListNode* p_node) {
    while (p_node) {
        cout << p_node->val << " ";
        p_node = p_node->next;
    }
}

void PrintNode(Node* p_node) {
    if (p_node == nullptr) {
        // do nothing and return
        return;
    }

    queue<Node*> node_queue;
    node_queue.push(p_node);  // for layer traverse
    queue<string> s_queue;  // saving each layer's tree node string
    s_queue.push(to_string(p_node->val));

    // find the max depth of the tree first
    int max_depth = MaxNodeDepth(p_node);
    // cout << "max_depth: " << max_depth << endl;
    // calculate the max digit for inditation
    int max_value = MaxNodeValue(p_node);
    // cout << "max_value: " << max_value << endl;
    int max_digit = 0;
    while (max_value != 0) {
        max_digit++;
        max_value /= 10;
    }

    int curr_depth = 1;
    // calculate how many spaces should be in the last row, imagine a width of a matrix
    int max_space_eacho_row = pow(2, max_depth-1) * max_digit * 2 + max_digit;
    for (int l=0; l<max_depth; ++l) {
        // elements number for current row
        int current_elements_in_row = pow(2, curr_depth-1);
        // calculate the spaces each blank  ==> spaces left divided by number of blanks
        int spaces_for_each_blank = (max_space_eacho_row-current_elements_in_row*max_digit)/(pow(2, curr_depth-1) + 1);

        // elements number for each level
        int level_size = s_queue.size();
        for (int i=0; i<level_size; ++i) {
            string s = s_queue.front();
            s_queue.pop();

            // output the strings stored in the s_queue represents each layers of elements
            for (int j=0; j<spaces_for_each_blank; ++j) {
                cout << " ";
            }
            cout << setw(max_digit) << s;
        }
        cout << endl;

        // prepare for next layer of traverse
        level_size = node_queue.size();
        for (int i=0; i<level_size; ++i) {
            Node* p_curr_node = node_queue.front();
            node_queue.pop();

            if (p_curr_node == nullptr) {
                // generate left right null child for counting
                node_queue.push(nullptr);
                node_queue.push(nullptr);
                // push null string to the s_queue
                s_queue.push(" ");
                s_queue.push(" ");
                continue;
            }

            if (p_curr_node->left != nullptr) {
                node_queue.push(p_curr_node->left);
                s_queue.push(to_string(p_curr_node->left->val));
            } else {
                node_queue.push(nullptr);
                s_queue.push(" ");
            }

            if (p_curr_node->right != nullptr) {
                node_queue.push(p_curr_node->right);
                s_queue.push(to_string(p_curr_node->right->val));
            } else {
                node_queue.push(nullptr);
                s_queue.push(" ");
            }
        }
        curr_depth++;
    }
}
