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
        dp[n] = {0,0};
        int i,j;
        for(i = n-1;i >= 0; i --){
            for(j = max(i,1);j<n;j++){
                dp[i].first = max(dp[i].first,sums[j+1] + dp[j+1].second);
                dp[i].second = min(dp[i].second,-(sums[j+1]) + dp[j+1].first);
            }
        }
        return dp[0].first;
    }
};


// int main(){
//     Solution solution;
//     vector<int> stones={
// 7,-6,5,10,5,-2
//     };

//     auto ret = solution.stoneGameVIII(stones);

//     return 0;
// }