#include"leetcode.h"

#define MAX 1000000007
class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.length();
        vector<int> pre(26,-1);
        vector<long long> dp(n,0);
        int i,j;
        int k;
        for(i = 0; i < n; i ++){
            k = pre[S[i]-'a'];
            pre[S[i]-'a'] = i;
            if(k==-1){dp[i]++;}
            for(j = max(0,k); j < i;j++){
                dp[i] += dp[j];
            }
            if(dp[i]>MAX){dp[i] %= MAX;}
        }
        long long ret = 0;
        for(i = 0; i < n; i ++){
            ret+=dp[i];
            //if(ret>MAX){ret %= MAX;}
        }
        if(ret>MAX){ret %= MAX;}
        return ret;
    }
};

// int main(){
//     Solution solution;

//     auto ret = solution.distinctSubseqII("abcaa");

//     return 0;
// }