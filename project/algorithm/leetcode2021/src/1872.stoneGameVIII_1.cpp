#include"leetcode.h"

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sums(n+1,0);
        sums[0] = 0;
        for(int i = 0; i < n; i ++){
            sums[i+1] = sums[i] + stones[i];
        }
        vector<pair<int,int>> dp(n+1,{INT_MIN,INT_MAX});
        dp[n-1] = {sums[n],-sums[n]};
        int i,j;
        for(i = n-2;i > 0; i --){
            dp[i].first = max(dp[i+1].first,sums[i+1]+dp[i+1].second);
            dp[i].second = min(dp[i+1].second,-(sums[i+1]) + dp[i+1].first);
        }
        return dp[1].first;
    }
};


// int main(){
//     Solution solution;
//     vector<int> stones={
// 4,5,-3,-6,-9,2,3
//     };

//     auto ret = solution.stoneGameVIII(stones);

//     return 0;
// }