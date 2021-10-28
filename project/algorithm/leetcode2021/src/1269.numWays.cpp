#include"leetcode.h"


class Solution {
private:
    int c(int x,int y){
        y=min(y,x-y);
        long long ret = 1;
        for(int i = 0;i<y;i++){
            ret*=(x-i);
        }
        for(int i = y; i > 0; i --){
            ret/=i;
        }
        return ret%1000000007;
    }
public:
    int numWays(int steps, int arrLen) {
        int len = min(steps >>1,arrLen-1);
        vector<vector<int>> dp(steps+1,vector<int>(len+1,0));
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(int i = 2; i <= steps;i++){
            dp[i][0] = dp[i-1][0];
            for(int j = 1;j <= min(i,len);j++){
                dp[i][j] = 0;
                // for(int k = j;k<=i;k++,k++){
                //     dp[i][j] += c(i,k);
                //     dp[i][j] %= 1000000007;
                // }
                dp[i][j] = (dp[i-1][j] + dp[i-2][j] + dp[i-1][j-1]) % 1000000007;
            }
        }

        long long ret = 1;
        for(int j = 1; j <= len;j ++){
            for(int i = j;i<=steps-j;i ++){
                if(i>j){
                    ret+=dp[i-1][j-1] * dp[steps-i][j];
                }
                else{
                    ret+=dp[i][j] * dp[steps-i][j];
                }
                ret %= 1000000007;
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.numWays(6,3);
    
//     return 0;

// }