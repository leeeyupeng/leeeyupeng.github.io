#include"leetcode.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i,j;
        int mid;
        i = 0,j = n;
        while(i<j){
            mid = (i+j)>>1;
            if(matrix[mid][0] > target){
                j = mid;
            }
            else if(matrix[mid][m-1] < target){
                i = mid+1;
            }
            else{
                i = mid,j = mid;
            }
        }
        int nn = i;
        if(i == n){return false;}
        i = 0,j = m;
        while(i<j){
            mid = (i+j)>>1;
            if(matrix[nn][mid] < target){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        if(i == m){return false;}
        return matrix[nn][i] == target;
    }
};