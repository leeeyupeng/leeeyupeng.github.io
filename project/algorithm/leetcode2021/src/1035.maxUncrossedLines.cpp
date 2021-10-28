#include"leetcode.h"

#define MAXN 510
#define MAXVALUE 2010
class Solution {
private:
    int dp[MAXN][MAXN];
    int counter[MAXVALUE];
    //int counter2[MAXVALUE];
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(counter,0,sizeof(int) * MAXVALUE);
        //memset(counter2,sizeof(int) * MAXVALUE));
        int n = nums1.size();
        int m = nums2.size();
        for(int i = n -1; i >= 0; i --){
            for(int j = m -1;j >= 0; j--){
                dp[i][j] = 0;
                if(nums1[i] == nums2[j]){
                    dp[i][j] ++;
                }
                if(j == m - 1){
                    dp[i][j] += counter[nums2[j]];  
                }
                else{
                    dp[i][j] += dp[i][j+1] + counter[nums2[j]];
                }
            }
            counter[nums1[i]] ++;
        }
        int ret = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(nums1[i] == nums2[j] && i+1<n && j+1<m){
                    ret+=dp[i+1][j+1];
                }
            }
        }
        return ret;
    }
};