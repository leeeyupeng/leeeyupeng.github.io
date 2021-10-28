#include"leetcode.h"

class Solution {
private:
    inline long long mymin(long long a,long long b,long long c){
        return min(min(a,b),c);
    }
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 2,0);
        dp[1]=1;
        int index2=1,index3=1,index5=1;
        for(int i = 2; i <= n; i ++){
            dp[i] = mymin(dp[index2] * 2,dp[index3] * 3,dp[index5] * 5);
            if(dp[i] == dp[index2] * 2){index2++;}
            if(dp[i] == dp[index3] * 3){index3++;}
            if(dp[i] == dp[index5] * 5){index5++;}
        }
        return dp[n];
    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.nthUglyNumber(1000);
//     return 0;
// }