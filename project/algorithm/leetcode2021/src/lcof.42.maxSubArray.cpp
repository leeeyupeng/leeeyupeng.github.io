#include"leetcode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0){return 0;}
        int ret = nums[0];
        int dp=nums[0];
        for(int i = 1; i < n; i ++){
            dp=max(dp + nums[i],nums[i]);
            ret = max(ret,dp);
        }
        return ret;
    }
};