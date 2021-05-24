#include"leetcode.h"

#define MAXN 102
class Solution {
private:
    int dp[MAXN][MAXN];
public:
    int strangePrinter(string s) {
        memset(dp,0,sizeof(int) * MAXN * MAXN);
        int n = s.length();
        int i,j,k,kk;
        for(i = 0; i < n; i ++){
            dp[i][i] = 1;
        }
        for(k = 1;k<n;k++){
            for(i = 0; i + k < n; i ++){
                j = i + k;
                if(k==1){
                    if(s[i] ==s[j]){dp[i][j] = dp[i][i];}
                    else{dp[i][j] = dp[i][i] + dp[j][j];}
                }
                else{
                    for(kk = i+1;kk<j;kk++){
                        if(dp[i][j] == 0){
                            dp[i][j] = dp[i][kk] + dp[kk][j] - 1;
                            if(s[kk-1] == s[kk+1]){
                                dp[i][j] = min(dp[i][j],dp[i][kk-1] + dp[kk+1][j] - 1 + 1);
                            }
                        }
                        else{
                            dp[i][j] = min(dp[i][j],dp[i][kk] + dp[kk][j] - 1);
                            if(s[kk-1] == s[kk+1]){
                                dp[i][j] = min(dp[i][j],dp[i][kk-1] + dp[kk+1][j] - 1 + 1);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};