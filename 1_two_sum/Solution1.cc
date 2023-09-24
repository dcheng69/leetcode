#include <iostream>
#include "Solution1.h"
using namespace std;

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    vector<int> ivec;

    for (int i=0; i<nums.size(); ++i) {
        for (int j=i+1; j<nums.size(); ++j) {
            if ((nums[i]+nums[j]) == target) {
                ivec.push_back(i);
                ivec.push_back(j);
            }
        }
    }

    return ivec;
}
