#include"leetcode.h"

#define MAXN 510
#define MAXVALUE 2010
class Solution {
private:
    int dp[MAXN][MAXN];
    //int counter[MAXVALUE];
    //int counter2[MAXVALUE];
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //memset(counter,0,sizeof(int) * MAXVALUE);
        //memset(counter2,sizeof(int) * MAXVALUE));
        int n = nums1.size();
        int m = nums2.size();
        int ret = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                dp[i][j] = 0;
                if(nums1[i] == nums2[j]){
                    if(i>0 && j > 0){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                if(i>0){
                    dp[i][j] = max(dp[i][j],dp[i-1][j]);
                }
                if(j>0){
                    dp[i][j] = max(dp[i][j],dp[i][j-1]);
                }
                //ret = max(ret,dp[i][j]);
            }
        }
        ret = dp[n-1][m-1];
        return ret;
    }
};