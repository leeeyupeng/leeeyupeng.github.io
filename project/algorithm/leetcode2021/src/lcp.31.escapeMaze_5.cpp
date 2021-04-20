#include"leetcode.h"

class Solution {
private:
    inline char _statecacl(char state){
        if((state&0b1)==0b1){return 0b111110;}
        char stateret = 0b0;        
        stateret |=  state&0b101000; 
        stateret |= (state&0b10) == 0b10 ? 0b100000 : 0b0;
        stateret |= (state&0b100) == 0b100 ? 0b010000 : 0b0;
        stateret |= ((stateret&0b101000) >> 1);
        return stateret;
    }
    inline char _statemerge(char statea,char stateb){
        return statea | stateb;
    }
public:
    bool escapeMaze(vector<vector<string>>& maze) {
        int times =maze.size();
        int n = maze[0].size();
        int m = maze[0][0].length();
        char offset[4][2]{{0,1},{0,-1},{1,0},{-1,0}};
        auto a = vector<vector<char>>(n,vector<char>(m,0));
        auto b = vector<vector<char>>(n,vector<char>(m,0));
        vector<vector<char>>* dp = &a;
        vector<vector<char>>* dpnext = &b;
        (*dp)[0][0] = 0b111111;

        int oi,oj;
        for(int t = 1; t < times; t++){
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                    if(maze[t][i][j]=='.'){
                        (*dpnext)[i][j] = (*dp)[i][j];
                        for(int o = 0; o < 4;o ++){
                            oi = i + offset[o][0];
                            oj = j + offset[o][1];
                            if(oi<0||oi>=n || oj < 0 || oj >=m){continue;}
                            (*dpnext)[i][j] = _statemerge((*dpnext)[i][j],(*dp)[oi][oj] & 0b010111);
                        }
                    }
                    else{
                        (*dpnext)[i][j] = _statecacl((*dp)[i][j]);
                        for(int o = 0; o < 4;o ++){
                            oi = i + offset[o][0];
                            oj = j + offset[o][1];
                            if(oi<0||oi>=n || oj < 0 || oj >=m){continue;}
                            (*dpnext)[i][j] = _statemerge((*dpnext)[i][j],_statecacl((*dp)[oi][oj]& 0b010111));
                        }
                    }
                }
            }
            if((*dpnext)[n-1][m-1]!=0){return true;}
            swap(dp,dpnext);
        }
        return false;
    }
};

// int main(){
//     vector<vector<string>> maze{

// {".#."},{".#."},{".#."}
//     };

//     Solution solution;
//     auto ret = solution.escapeMaze(maze);

//     return 0;
// }