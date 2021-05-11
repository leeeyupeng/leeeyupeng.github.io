#include"leetcode.h"

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sums(m+1,vector<int>(n+1,0));
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){                
                sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i][j];
            }
        }
        int value;
        int ret=INT_MIN;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                for(int ii = i; ii <= m; ii++){
                    for(int jj = j; jj <= n;jj++){
                        value = sums[ii][jj] - (sums[i-1][jj] + sums[ii][j-1] - sums[i-1][j-1]);
                        if(value<=k){
                            ret = max(ret,value);
                        }
                    }
                }
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> matrix{
// {5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}
//     };
//     int k = 3;
//     auto ret = solution.maxSumSubmatrix(matrix,k);

//     return 0;
// }