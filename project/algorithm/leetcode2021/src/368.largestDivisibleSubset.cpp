#include"leetcode.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> dp(n);
        for(int i = 0;  i < n; i ++){
            dp[i] = {1,-1};
        }
        int retnums = 1;
        int retlargestnum = 0;
        for(int i = 1; i < n; i ++){
            for(int j = i-1; j >= 0; j --){
                if(dp[i].first > j + 1 + 1){break;}
                if(nums[i] % nums[j] == 0){
                    if(dp[i].first < dp[j].first + 1){
                        dp[i] = {dp[j].first + 1,j};
                    }                    
                }
            }
            if(dp[i].first > retnums){
                retnums = dp[i].first;
                retlargestnum = i;
            }
        }

        vector<int> ret(retnums,0);
        int index = retlargestnum;
        for(int i = retnums- 1; i >=0;i--){
            ret[i] = nums[index];
            index = dp[index].second;
        }
        return ret;
    }
};