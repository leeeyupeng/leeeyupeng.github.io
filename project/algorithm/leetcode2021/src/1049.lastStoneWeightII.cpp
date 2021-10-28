#include"leetcode.h"


#define MAXHALF 3000
#define MAXSUM 6010
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<char>> dp(n+1,vector<char>(MAXSUM,0));
        dp[0][MAXHALF] = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < MAXSUM;j ++){
                if(j+stones[i-1]<MAXSUM){
                    dp[i][j+stones[i-1]]|=dp[i-1][j];
                }
                if(j-stones[i-1]>=0){
                    dp[i][j-stones[i-1]]|=dp[i-1][j];
                }
            }
        }

        for(int j = MAXHALF;j < MAXSUM;j++){
            if(dp[n][j]==1){
                return j - MAXHALF;
            }
        }
        return 0;
    }
};

// int main(){
//     vector<int> stones={2,7,4,1,8,1};
//     Solution solution;
//     auto ret = solution.lastStoneWeightII(stones);

//     return 0;
// }