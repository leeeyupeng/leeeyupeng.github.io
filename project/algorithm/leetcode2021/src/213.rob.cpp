#include"leetcode.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        pair<int,int> dp;
        int n = nums.size();
        dp = {0,nums[0]};
        int ret = max(dp.first,dp.second);
        for(int i = 1; i < n; i ++){
            dp = {max(dp.first,dp.second),dp.first + nums[i]};
        }
        ret = max(ret,max(dp.first,dp.second - nums[0]));

        dp = {0,0};
        for(int i = 1; i < n; i ++){
            dp = {max(dp.first,dp.second),dp.first + nums[i]};
        }
        ret = max(ret,max(dp.first,dp.second));
        return ret;
    }
};