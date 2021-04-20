#include"leetcode.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ret = INT_MAX;
        for(int i = 0; i < n; i ++){
            ret = min(ret,nums[i]);
        }
        return ret;
    }
};