#include"leetcode.h"


class Solution {
private:
public:
    int numWays(int steps, int arrLen) {
        int len = min(steps >>1,arrLen-1);
        vector<vector<int>> dp(steps+1,vector<int>(len+1,0));
        dp[0][0] = 1;
        dp[1][1] = 0;
        for(int i = 1; i <= steps;i++){
            //dp[i][0] = dp[i-1][0];
            for(int j = 1;j<=min(i,len);j++){
                for(int i1 = j-1;i1<=i-1;i1++){
                    dp[i][j] += dp[i1][j-1];
                    dp[i][j] %= 1000000007;
                }
                //dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 1000000007;
            }
        }
        vector<vector<int>> dp2(steps+1,vector<int>(len+1,0));
        dp2[0][0] = 1;
        for(int i = 1; i <= steps;i++){
            dp2[i][0] = 1;
        }
        for(int j = 1;j<=len;j++){
            dp2[0][j] = 1;
        }
        for(int i = 1;i <= steps; i ++){
            for(int j = 1; j <= min(i>>1,len);j++){
                dp2[i][j] = dp2[i][j-1];
                for(int i1 = j;i1<=i-j;i1++){
                    for(int i2 = i1;i2<=i-j;i2++){
                        dp2[i][j] += (dp[i1][j] * dp2[i2-i1][min((i2-i1)>>1,j)] * dp[i-i2][j]) % 1000000007;
                        dp2[i][j] %= 1000000007;
                    }
                }
            }
        }
        return dp2[steps][len];
    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.numWays(6,3);
    
//     return 0;

// }