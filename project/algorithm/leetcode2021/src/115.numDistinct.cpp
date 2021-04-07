#include"leetcode.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m==0){return 1;}
        if(n==0){return 0;}
        vector<long long> dp(m,0);
        for(int i = 0; i < n; i ++){            
            for(int j = m-1;j >0;j --){
                if(s[i] == t[j]){
                    dp[j] += dp[j-1];
                }
            }
            dp[0] += s[i] == t[0]?1:0;
        }
        return dp[m-1];
    }
};