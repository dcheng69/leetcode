#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include "Solution331.h"
#include "PrintX.h"
using namespace std;
#define DEBUG

vector<string> getStringVector(string str) {
    vector<string> s_vec;
    istringstream ss(str);
    string temp_str;

    while (getline(ss, temp_str, ',')) {
#ifdef DEBUG
        cout << temp_str <<" ";
#endif
        s_vec.push_back(temp_str);
    }
#ifdef DEBUG
    cout << endl;
#endif
    return s_vec;
}

bool Solution::isValidSerialization(string preorder) {
    bool ret = false;
    vector<string> s_vec = getStringVector(preorder);
    stack<string> s_stk;
    for (int i=0; i<s_vec.size(); i++) {
        s_stk.push(s_vec[i]);
        int loop_count = 1;
        while (loop_count--) {
            if (s_stk.size() >= 3 && s_stk.top() == "#") {
                // check the last three elements
                string top_1 = s_stk.top();
                s_stk.pop();
                string top_2 = s_stk.top();
                s_stk.pop();
                string top_3 = s_stk.top();
                s_stk.pop();

#ifdef DEBUG
                cout << top_3 <<" ";
                cout << top_2 <<" ";
                cout << top_1 <<" ";
                cout << endl << endl;;
#endif
                if (top_1 == "#" && top_2 == "#" && top_3 != "#") {
                    s_stk.push("#");
                    loop_count++;
                } else if (top_1 == "#" && top_2 == "#" && top_3 == "#") {
                    ret = false;
                    break;
                } else {
                    s_stk.push(top_3);
                    s_stk.push(top_2);
                    s_stk.push(top_1);
                }

            }
        }
    }

    // check the size and the last node
    if (s_stk.size() == 1 && s_stk.top() == "#") {
        ret = true;
    } else {
        ret = false;
    }

    return ret;
}
