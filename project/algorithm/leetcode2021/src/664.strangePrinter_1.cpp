#include"leetcode.h"

#define MAXN 102
class Solution {
private:
    int dp[MAXN][MAXN];
public:
    int strangePrinter(string s) {
        memset(dp,0,sizeof(int) * MAXN * MAXN);
        int n = s.length();
        int i=0,j = 1;
        while(j<n){
            if(s[i] == s[j]){j++;}
            else{i++;s[i] = s[j];j++;}
        }
        n = i + 1;
        int k,k1,k2;
        for(i = 0; i < n; i ++){
            dp[i][i] = 1;
            if(i+1<n){
                dp[i][i+1] = 2;
            }
        }
        for(k = 2;k<n;k++){
            for(i = 0; i + k < n; i ++){
                j = i + k;
                dp[i][j] = j-i+1;
                for(k1 = i; k1<j;k1++){
                    for(k2 = k1;k2<=j;k2++){
                        if(s[k1]==s[k2]){
                            dp[i][j] = min(dp[i][j],(k1-1>= i ? dp[i][k1-1]:0) + (k2-1>=k1+1?dp[k1+1][k2-1]:0) + (k2+1<=j?dp[k2+1][j]:0) + 1);
                            dp[i][j] = min(dp[i][j],dp[i][k1]+dp[k1][k2]+dp[k2][j]-2);
                        }
                    }
                }                
            }
        }
        return dp[0][n-1];
    }
};