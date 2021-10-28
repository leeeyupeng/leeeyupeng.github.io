#include"leetcode.h"

#define MAX 10010
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> counter(MAX,0);
        for(int i = 0; i < n; i ++){
            counter[nums[i]] ++;
        }
        vector<int> dp(MAX,0);
        dp[1] = counter[1];
        for(int i = 2;i < MAX;i++){
            dp[i] = dp[i-2] + counter[i] * i;
            dp[i] = max(dp[i],dp[i-1]);
        }
        return max(dp[MAX-2],dp[MAX-1]);
    }
};