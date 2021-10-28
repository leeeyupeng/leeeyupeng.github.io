#include"leetcode.h"

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<int>> dp(n+1,vector<int>(minProfit+1,0));
        dp[0][0] = 1;
        for(int j = 0; j < m; j ++){
            for(int i = 0; i <= n-group[j]; i ++){
                for(int p = 0;p <= minProfit; p++){
                    dp[i+group[j]][min(minProfit,p+profit[j])] += dp[i][p];
                    dp[i+group[j]][min(minProfit,p+profit[j])] %= 1000000007;
                }
            }
        }

        int ret = 0;
        for(int i = 0; i <= n; i ++){
            ret+=dp[i][minProfit];
            ret%=1000000007;
        }
        return ret;
    }
};