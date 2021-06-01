#include"leetcode.h"

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ysums = 0;
        for(int i = 0; i < n; i ++){
            ysums = 0;
            for(int j = 0; j < m;j ++){
                ysums+=matrix[i][j];
                matrix[i][j] = (i>0?matrix[i-1][j]:0) + ysums;
            }
        }

        map<int,int> ymap;
        int ret = 0;
        for(int ix1 = 0;ix1 < n; ix1 ++){
            for(int ix2 = ix1;ix2<n;ix2++){
                ymap.clear();                
                for(int j = m-1;j >= 0;j --){
                    ysums = matrix[ix2][j] - (ix1>0?matrix[ix1-1][j]:0);
                    if(ymap.find(target+ysums)!=ymap.end()){ret+=ymap[target+ysums];}
                    if(ymap.find(ysums)==ymap.end()){ymap.insert({ysums,0});}
                    ymap[ysums]++;
                }
                if(ymap.find(target)!=ymap.end()){ret+=ymap[target];}
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> matrix={
//         {0,1,0},{1,1,1},{0,1,0}
//     };

//     int target = 0;
//     auto ret = solution.numSubmatrixSumTarget(matrix,target);
//     return 0;
// }