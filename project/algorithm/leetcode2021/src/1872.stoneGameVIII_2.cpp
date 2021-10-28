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
        int dp[100010];
        dp[n-1] = sums[n];
        int i,j;
        for(i = n-2;i > 0; i --){
            dp[i] = max(dp[i+1],sums[i+1]-dp[i+1]);
        }
        return dp[1];
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