#include"leetcode.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i=0,j=0;
        char state=0;
        int rect[]{0,0,n-1,n-1};
        int offset[4][2]{{0,1},{1,0},{0,-1},{-1,0}};
        int rectoffset[4][4]{{1,0,0,0},{0,0,0,-1},{0,0,-1,0},{0,1,0,0}};
        int nn = n * n;
        int counter=1;
        vector<vector<int>> ret(n,vector<int>(n,0));
        while(counter<=nn){  
            ret[i][j] = counter++;
            if(i==0&&j==0){}
            else if((state == 0 && j == rect[3]) 
            || (state==1 && i == rect[2]) 
            || (state == 2 && j == rect[1]) 
            || (state == 3 && i == rect[0])){                
                rect[0] += rectoffset[state][0];
                rect[1] += rectoffset[state][1];
                rect[2] += rectoffset[state][2];
                rect[3] += rectoffset[state][3];
                state ++;
                state%=4;             
            }
            i += offset[state][0];
            j += offset[state][1];
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.generateMatrix(4);
//     return 0;
// }