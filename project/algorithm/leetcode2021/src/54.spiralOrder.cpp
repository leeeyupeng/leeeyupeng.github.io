#include"leetcode.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0){return {};}
        int n = matrix[0].size();
        int i = 0,j = 0;
        int nm = n * m;
        vector<int> ret(nm,0);
        int mu=0,md=m-1;
        int nl = 0,nr = n-1;
        int counter = 0;
        char flag = 0;
        while(counter < nm){
            ret[counter++] = matrix[i][j];
            switch (flag)
            {
            case 0:
                j++;
                if(j > nr){
                    mu ++;
                    j --;
                    i++;
                    flag = 1;
                }
                break;
            case 1:
                i++;
                if(i > md){
                    nr --;
                    i --;
                    j--;
                    flag = 2;
                }
                break;
            case 2:
                j--;
                if(j < nl){
                    md --;
                    j ++;
                    i--;
                    flag = 3;
                }
                break;
            case 3:
                i--;
                if(i < mu){
                    nl++;
                    i++;
                    j++;
                    flag = 0;
                }
                break;
            default:
                break;
            }
        }
        return ret;
    }
};

// int main()
// {
//     vector<vector<int>> matrix{
// {1,2,3,4},{5,6,7,8},{9,10,11,12}
//     };

//     Solution solution;
//     auto ret = solution.spiralOrder(matrix);
//     return 0;
// }