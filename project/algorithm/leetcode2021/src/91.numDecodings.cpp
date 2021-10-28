#include"leetcode.h"

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        if(s[0] == '0'){
            dp[1] = 0;
        }
        else{
            dp[1] = 1;
        }
        for(int i = 1; i < n; i ++){
            if(s[i] == '0'){
                dp[i+1] += 0;
            }
            else{
                dp[i+1] += dp[i];
            }
            if(s[i-1]=='1'){
                dp[i+1] += dp[i-1];
            }
            else if(s[i-1] == '2' && s[i] <= '6'){
                dp[i+1] += dp[i-1];
            }
            else{

            }
        }

        return dp[n];
    }
};