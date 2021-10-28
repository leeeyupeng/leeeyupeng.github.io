#include"leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.length();
        int pn = p.length();
        vector<vector<char>> dp(sn+1,vector<char>(pn+1,0));
        dp[0][0] = 1;
        for(int j = 1; j <= pn; j ++){
            if(p[j-1] == '*'){
                dp[0][j] |= dp[0][j-2];
            }
        }
        for(int i = 1; i <= sn; i ++){
            for(int j = 1; j <= pn; j ++){
                if(s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2] == '.' || s[i-1] == p[j-2]){
                        dp[i][j] |= dp[i-1][j];
                    }
                }
            }
        }
        return dp[sn][pn];
    }
};

// int main(){
//     Solution solution;
//     string s = "aaabca";
//     string p = "a*bca";
//     auto ret = solution.isMatch(s,p);
//     return 0;
// }