#include"leetcode.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m==0){return 1;}
        if(n==0){return 0;}
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        dp[0][0] = s[0]==t[0]?1:0;
        for(int i = 1; i < n; i ++){
            dp[i][0] = dp[i-1][0] + (s[i] == t[0]?1:0);
            for(int j = 1; j < m; j ++){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};