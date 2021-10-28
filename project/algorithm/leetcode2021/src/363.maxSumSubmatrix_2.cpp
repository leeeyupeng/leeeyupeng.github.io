#include"leetcode.h"

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ret = INT_MIN;
        vector<int> sums(n,0);
        set<int> sumset;
        set<int>::iterator ite;
        for(int i = 0; i < m; i ++){
            for(int c = 0;c<n; c++){
                sums[c] = 0;
            }
            for(int j = i; j < m; j ++){
                for(int c = 0;c<n; c++){
                    sums[c] += matrix[j][c];
                }
                sumset.clear();
                int s = 0;
                for(int c = 0; c<n;c++){
                    s+=sums[c];                    
                    ite = sumset.lower_bound(s - k);
                    if(ite!=sumset.end()){
                        ret = max(ret,s - (*ite));
                    }                    
                    sumset.insert(s);
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