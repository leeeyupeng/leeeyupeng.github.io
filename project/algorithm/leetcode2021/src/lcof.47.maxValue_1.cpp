#include"leetcode.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]) + grid[i][j];
            }
        }
        return dp[m][n];
    }
};

// int main(){
//     vector<vector<int>> grid{
//         {1,3,1},
//         {1,5,1},
//         {4,2,1}
//     };

//     Solution solution;
//     auto ret = solution.maxValue(grid);

//     return 0;
// }