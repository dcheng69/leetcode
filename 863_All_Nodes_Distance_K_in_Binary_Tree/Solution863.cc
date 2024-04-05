#include <unordered_map>
#include <queue>
#include "Solution863.h"
using namespace std;

std::vector<int> Solution::distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> hash_map;
    vector<int> i_vec;
    if (!root) {
        return i_vec;
    }
    if (0 == k && target != nullptr) {
        i_vec.push_back(target->val);
        return i_vec;
    }

    queue<TreeNode*> t_que;
    t_que.push(root);
    TreeNode* temp;
    while (!t_que.empty()) {
        temp = t_que.front();
        t_que.pop();
        if (temp->left) {
            hash_map[temp->left] = temp;
            t_que.push(temp->left);
        }
        if (temp->right) {
            hash_map[temp->right] = temp;
            t_que.push(temp->right);
        }
    }
    if (hash_map.size() == 0 && k > 0) {
        return i_vec;
    }

    // perform a BFS search starting from the target node
    unordered_map<TreeNode*, bool> visited_hash_map;
    t_que.push(target);
    visited_hash_map[target] = true;
    int distance = -1;
    while (!t_que.empty()) {
        distance++;
        if (distance == k) {
            while (!t_que.empty()) {
                i_vec.push_back(t_que.front()->val);
                t_que.pop();
            }
            break;
        }
        int size = t_que.size();
        while (size--) {
            temp = t_que.front();
            t_que.pop();

            if (temp->left) {
                if (visited_hash_map.find(temp->left) == visited_hash_map.end()) {
                    t_que.push(temp->left);
                    visited_hash_map[temp->left] = true;
                }
            }
            if (temp->right) {
                if (visited_hash_map.find(temp->right) == visited_hash_map.end()) {
                    t_que.push(temp->right);
                    visited_hash_map[temp->right] = true;
                }
            }
            if (hash_map.find(temp) != hash_map.end()) {
                if (visited_hash_map.find(hash_map[temp]) == visited_hash_map.end()) {
                    t_que.push(hash_map[temp]);
                    visited_hash_map[hash_map[temp]] = true;
                }
            }
        }
    }

    return i_vec;
}
