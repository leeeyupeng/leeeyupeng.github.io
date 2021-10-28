#include"leetcode.h"

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int  cc[10];
        for(int i = 0; i < 9; i ++){
            cc[i+1] = cost[i];
        }
        int dp[5010];
        memset(dp,0xFF,sizeof(int) * (target + 1));
        dp[0] = 0;
        for(int i = 1; i < 10;i ++){
            for(int j = 0; j <= target; j ++){
                if(j-cc[i]>=0 && dp[j-cc[i]]!=-1){
                    dp[j] = max(dp[j],dp[j-cc[i]] + 1);
                }
            }
        }
        if(dp[target]== -1){return "0";}
        string ret;
        int tt = target;
        while(tt > 0){
            for(int i = 9; i >= 1;i --){
                if(tt-cc[i] >= 0 && dp[tt] == dp[tt-cc[i]] + 1){
                    ret.push_back(i+'0');
                    tt -= cc[i];
                    break;
                }
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> cost={
//         4,3,2,5,6,7,2,5,5
//     };
//     int target = 9;
//     auto ret = solution.largestNumber(cost,target);

//     return 0;
// }