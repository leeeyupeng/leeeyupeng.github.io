#include"leetcode.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        for(int j = 1; j <= target; j ++){
            for(int i = 0;i < n; i ++){
                if(j - nums[i]>=0){
                    dp[j] += dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};

// int main(){
//     vector<int> nums{1,2,3};
//     int target = 4;
//     Solution solution;
//     auto ret = solution.combinationSum4(nums,target);
//     return 0;
// }