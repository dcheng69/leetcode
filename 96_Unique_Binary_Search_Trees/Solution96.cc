#include <iostream>
#include <vector>
#include "Solution96.h"
using namespace std;
#define SOLUTION_2

#ifdef SOLUTION_1
int Solution::numTrees(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int ret = 0;
    for (int i=1; i <= n; i++) {
        ret += numTrees(i-1) * numTrees(n-i);
    }

    return ret;
}
#endif

#ifdef SOLUTION_2
/**
 * Non recursive solution
 */
int Solution::numTrees(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    vector<int> i_vec(n+1);
    i_vec[0] = i_vec[1] = 1;

    for (int i = 2; i <= n; i++) {
        int ret = 0;
        for (int j=1; j<=i; j++) {
            ret += i_vec[j-1] * i_vec[i-j];
        }
        i_vec[i] = ret;
    }

    return i_vec[n];
}
#endif
