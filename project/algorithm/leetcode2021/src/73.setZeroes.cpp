#include"leetcode.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0){return;}
        int m = matrix[0].size();
        bool firstn = false;
        bool firstm=false;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(matrix[i][j] == 0){
                    if(i == 0){firstn = true;}
                    if(j == 0){firstm = true;}
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i = n-1; i > 0; i --){
            for(int j = m - 1; j > 0; j --){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstm){
            for(int i = 0; i < n; i ++){
                matrix[i][0] = 0;
            }
        }
        if(firstn){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }

        return ;
    }
};