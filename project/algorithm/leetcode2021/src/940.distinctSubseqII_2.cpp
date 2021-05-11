#include"leetcode.h"

#define MAX 1000000007
class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.length();
        vector<int> pre(26,-1);
        vector<long long> dp(n,0);
        vector<long long> dpsums(n+1,0);
        int i,j;
        int k;
        for(i = 0; i < n; i ++){
            k = pre[S[i]-'a'];
            pre[S[i]-'a'] = i;
            if(k==-1){dp[i]++;}
            dp[i] += dpsums[i] + MAX;
            dp[i] -= dpsums[max(0,k)];
            if(dp[i]>MAX){dp[i] %= MAX;}
            dpsums[i+1] = dpsums[i] + dp[i];
        }
        long long ret = dpsums[n];
        if(ret>MAX){ret %= MAX;}
        return ret;
    }
};

// int main(){
//     Solution solution;

//     auto ret = solution.distinctSubseqII("abcaa");

//     return 0;
// }