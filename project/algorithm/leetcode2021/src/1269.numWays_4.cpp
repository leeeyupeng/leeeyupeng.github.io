#include"leetcode.h"


class Solution {
public:
    int numWays(int steps, int arrLen) {
        int len = min(steps >>1,arrLen-1);
        vector<vector<int>> dp(steps+1,vector<int>(len+1,0));
        dp[0][0] = 1;
        for(int i = 1;i<=steps; i++){
            for(int j = 0;j<=min(i,len);j++){
                dp[i][j] = dp[i-1][j];
                if(j-1>=0){
                    dp[i][j] += dp[i-1][j-1];
                    if(dp[i][j]>=1000000007)
                        dp[i][j] -= 1000000007;
                }
                if(j+1<=len){
                    dp[i][j] += dp[i-1][j+1];
                    if(dp[i][j]>=1000000007)
                        dp[i][j] -= 1000000007;
                }
            }
        }
        return dp[steps][0];
    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.numWays(60,3);
    
//     return 0;

// }