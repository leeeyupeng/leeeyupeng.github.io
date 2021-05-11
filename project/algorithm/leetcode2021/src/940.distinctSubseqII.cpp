#include"leetcode.h"

#define MAX 1000000007
class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.length();
        vector<int> next(n+1,0);
        next[0] = -1;
        int k = -1;
        int i = 0;
        int j;
        while(i<n){
            while(k!=-1&&S[k]!=S[i]){
                k = next[k];
            }
            i++;k++;
            next[i] = k;
        }

        vector<long long> dp(n,0);
        dp[0] = 1;
        for(i = 1; i < n; i ++){
            k = next[i+1];
            if(k==0){dp[i]++;}
            for(j = max(0,k-1); j < i;j++){
                dp[i] += dp[j];
            }
            while(dp[i]>MAX){dp[i] -= MAX;}
        }
        long long ret = 0;
        for(i = 0; i < n; i ++){
            ret+=dp[i];
            while(ret>MAX){ret -= MAX;}
        }
        return ret;
    }
};

// int main(){
//     Solution solution;

//     auto ret = solution.distinctSubseqII("abcaa");

//     return 0;
// }