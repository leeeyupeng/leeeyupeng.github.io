#include"leetcode.h"

#define RETMAX 2010
#define MAXNUM (1<<10)
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n-k+1;
        vector<int> numsxor(m,0);
        int value=0;
        for(int i = 0; i < k; i ++){
            value ^= nums[i];
        }
        numsxor[0] = value;
        for(int i = k;i < n; i ++){
            value ^= nums[i];
            value ^= nums[i-k];
            numsxor[i-k+1] = value;                      
        }
        
        vector<pair<int,int>> dp[2]{vector<pair<int,int>>(MAXNUM,{RETMAX,0}),vector<pair<int,int>>(MAXNUM,{RETMAX,0})};
        dp[1][0]={0,0};
        int dpindexlast;
        int dpindex;
        for(int i = 0; i < m; i ++){
            dpindexlast = (i-1)&0x1;
            dpindex = i & 0x1;
            dp[dpindex][numsxor[i]].first = min(dp[dpindex][numsxor[i]].first,dp[dpindexlast][0].first + (numsxor[i]==0?0:1));
            dp[dpindex][numsxor[i]].second = 0;
            for(int b = 1; b<MAXNUM;b++){
                if(dp[dpindexlast][b].first >= RETMAX){continue;}
                dp[dpindex][numsxor[i]].first = min(dp[dpindex][numsxor[i]].first,dp[dpindexlast][b].first + (numsxor[i]==0?0:1));

                dp[dpindex][numsxor[i]^b]={dp[dpindexlast][b].first + ((numsxor[i]^b) == 0?0:1),0};
                if(dp[dpindexlast][b].second < k-1){
                    dp[dpindex][numsxor[i]^b]={dp[dpindexlast][b].first + ((numsxor[i]^b) == 0?0:1),dp[dpindexlast][b].second + 1};
                }

                dp[dpindexlast][b].first = RETMAX;
            }
            dp[dpindexlast][0].first = RETMAX;
        }

        dpindex = (m-1) & 0x1;
        int ret = RETMAX;
        for(int b = 0; b<MAXNUM;b++){
            ret = min(ret,dp[dpindex][b].first);
        }
        return ret;
    }
};

// int main(){
//     Solution solution;

//     vector<int> nums={3,4,5,2,1,7,3,4,7};
//     int k= 3;
//     auto ret = solution.minChanges(nums,k);

//     return 0;
// }