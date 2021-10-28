#include"leetcode.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m==0){return 1;}
        if(n==0){return 0;}
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        for(int i = 0; i < n; i ++){
            dp[i][0] = s[i] == t[0]?1:0;
            for(int j = 1; j < m;j ++){
                if(s[i] == t[j]){
                    for(int k = 0; k < i; k ++){
                        dp[i][j] += dp[k][j-1];
                    }
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i ++){
            ret += dp[i][m-1];
        }
        return ret;
    }
};