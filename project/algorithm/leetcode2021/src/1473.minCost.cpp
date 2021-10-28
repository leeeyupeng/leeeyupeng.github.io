#include"leetcode.h"

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(m+1,vector<int>(n,-1)));
        for(int j = 0;j < n;j++){
            dp[0][0][j] = 0;
        }
        vector<int> vt(m,0);
        if(houses[m-1]!=0){vt[m-1]=1;}
        for(int i = m-2;i>=0;i--){
            if(houses[i]!=0 && houses[i]!=houses[i+1]){
                vt[i]=vt[i+1]+1;
            }
            else{
                vt[i] = vt[i+1];
            }
        }
        for(int i = 0; i < m; i ++){
            for(int t = 1;t <= min(i+1,target-vt[i] + 1); t++){
                for(int j = 0;j < n;j++){
                    if(houses[i] == 0){
                        for(int jj = 0;jj < n;jj++){
                            if(j == jj){                                
                                if(dp[i][t][jj]!=-1){
                                    if(dp[i+1][t][j] == -1){
                                        dp[i+1][t][j] = dp[i][t][jj] + cost[i][j];
                                    }
                                    else{
                                        dp[i+1][t][j] = min(dp[i+1][t][j],dp[i][t][jj] + cost[i][j]);
                                    }
                                }
                            }
                            else{                                
                                if(dp[i][t-1][jj] !=-1){
                                    if(dp[i+1][t][j] == -1){
                                        dp[i+1][t][j] = dp[i][t-1][jj] + cost[i][j];
                                    }
                                    else{
                                        dp[i+1][t][j] = min(dp[i+1][t][j],dp[i][t-1][jj] + cost[i][j]);
                                    }
                                }                                                          
                            }
                        }
                    }
                    else if(houses[i] == j + 1){
                        for(int jj = 0;jj < n;jj++){
                            if(j == jj){                                
                                if(dp[i][t][jj]!=-1){
                                    if(dp[i+1][t][j] == -1){
                                        dp[i+1][t][j] = dp[i][t][jj];
                                    }
                                    else{
                                        dp[i+1][t][j] = min(dp[i+1][t][j],dp[i][t][jj]);
                                    }
                                }
                            }
                            else{                                
                                if(dp[i][t-1][jj] !=-1){
                                    if(dp[i+1][t][j] == -1){
                                        dp[i+1][t][j] = dp[i][t-1][jj];
                                    }
                                    else{
                                        dp[i+1][t][j] = min(dp[i+1][t][j],dp[i][t-1][jj]);
                                    }
                                }                                
                            }
                        }
                    }
                    else{
                        dp[i+1][t][j] = -1;
                    }
                }
            }
        }

        int ret = -1;
        for(int j = 0;j < n;j++){
            if(dp[m][target][j] == -1){
                continue;
            }
            else if(ret == -1){
                ret = dp[m][target][j];
            }
            else{
                ret = min(ret,dp[m][target][j]);
            }
        }
        return ret;
    }
};

// int main(){
//     vector<int> houses{0,0,0,0,0};
//     vector<vector<int>> cost{{1,10},{10,1},{10,1},{1,10},{5,1}};
//     int m=5;
//     int n=2;
//     int target=3;
//     Solution solution;

//     auto ret = solution.minCost(houses,cost,m,n,target);

//     return 0;
// }