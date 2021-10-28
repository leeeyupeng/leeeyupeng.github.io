#include"leetcode.h"

#define MAXN 102
class Solution {
private:
    int n;
    int dp[MAXN][MAXN];
    int dfs(string &s,int i,int j){
        if(i>j){return 0;}
        if(dp[i][j]!=0){return dp[i][j];}
        int ret = j - i + 1;
        for(int k1 = i; k1 < j; k1++){
            for(int k2 = k1+1;k2<=j;k2++){
                if(s[k1] == s[k2]){
                    ret = min(ret,dfs(s,i,k1-1) + dfs(s,k1+1,k2-1) + dfs(s,k2+1,j)+1);
                    if(!(i == k1 && j == k2)){ret = min(ret,dfs(s,i,k1) + dfs(s,k1,k2) + dfs(s,k2,j)-2);}                    
                }
            }
        }

        dp[i][j] = ret;
        return ret;
    }
public:
    int strangePrinter(string s) {
        memset(dp,0,sizeof(int) * MAXN * MAXN);
        n = s.length();
        int i=0,j = 1;
        while(j<n){
            if(s[i] == s[j]){j++;}
            else{i++;s[i] = s[j];j++;}
        }
        n = i + 1;
        int k,k1,k2;
        for(i = 0; i < n; i ++){
            dp[i][i] = 1;
            if(i+1<n){
                dp[i][i+1] = 2;
            }
        }

        return dfs(s,0,n-1);
    }
};



// int main(){
//     string str = "jfioasodfjqoidddfjqlkwejfsasdfddddfasdfqwfdfvbrthrethdfasdfasdfasdfioasdj";
//     Solution solution;
//     auto ret = solution.strangePrinter(str);
//     return 0;
// }