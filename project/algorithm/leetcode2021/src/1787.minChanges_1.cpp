#include"leetcode.h"

#define RETMAX 2010
#define MAXBIT (1<<10)
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
        
        vector<int> dp1[2];
        dp1[0] = vector<int>(MAXBIT,RETMAX);
        dp1[1] = vector<int>(MAXBIT,RETMAX);
        vector<int> dp2[2];
        dp2[0] = vector<int>(k,RETMAX);
        dp2[1] = vector<int>(k,RETMAX);
        dp1[0][numsxor[0]]=numsxor[0]==0?0:1;
        dp2[0][0] = numsxor[0]==0?0:1;
        int dpindexlast;
        int dpindex;
        for(int i = 1; i < m; i ++){
            dpindexlast = (i-1)&0x1;
            dpindex = i & 0x1;
            for(int b = 0; b<MAXBIT;b++){
                dp1[dpindex][numsxor[i]] = min(dp1[dpindex][numsxor[i]],dp1[dpindexlast][b] + (numsxor[i] == 0?0:1));
                dp1[dpindex][numsxor[i]^b] = min(dp1[dpindex][numsxor[i]^b],dp1[dpindexlast][b] + ((numsxor[i]^b) == 0?0:1));
                dp2[dpindex][0] = min(dp2[dpindex][0],dp1[dpindex][numsxor[i]]);
                //dp2[dpindex][1] = min(dp2[dpindex][1],dp1[dpindexlast][b] + ((numsxor[i]^b) == 0?0:1));
                dp1[dpindexlast][b] = RETMAX;
            }
            for(int ik = 0; ik < k-1;ik++){                
                dp1[dpindex][numsxor[i]] = min(dp1[dpindex][numsxor[i]],dp2[dpindexlast][ik] + (numsxor[i] == 0?0:1));
                dp1[dpindex][numsxor[i]] = min(dp1[dpindex][numsxor[i]],dp2[dpindexlast][ik] + ((numsxor[i-1] ^ numsxor[i]) == 0?0:1));
                dp2[dpindex][ik+1] = min(dp2[dpindex][ik+1],dp2[dpindexlast][ik] + ((numsxor[i-1] ^ numsxor[i])==0?0:1));
                dp2[dpindexlast][ik] = RETMAX;
            }

            dp2[dpindexlast][k-1] = RETMAX;
        }

        dpindex = (m-1) & 0x1;
        int ret = RETMAX;
        for(int b = 0; b<MAXBIT;b++){
            ret = min(ret,dp1[dpindex][b]);
        }
        for(int ik = 0; ik < k; ik ++){
            ret = min(ret,dp2[dpindex][ik]);
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