#include"leetcode.h"

class Solution {
private:
    int times;
    int n,m;
    vector<pair<int,int>> offset{{0,1},{1,0},{0,-1},{-1,0}};
    inline char cacl(char a,char b){
        if(a==b){return a;}
        else if(a == 0b0){return b;}
        else if(b == 0b0){return a;}
        else if(a == 0b1){return a;}
        else if(b == 0b1){return b;}
        else{
            if(a == 0b10101){
                if(b == 0b00011){
                    return 0b01011;
                }
            }
            if((a&0b111) == (b&0b111)){
                if((a&0b10000) == 0b10000){return a;}
                else if((b&0b10000) == 0b10000){return b;}
                else if((a&0b01000) == 0b01000){return a;}
                else if((b&0b01000) == 0b01000){return b;}
                return a;
            }
            else if((a&0b111) < (b&0b111)){
                return a;
            }
            else{
                return b;
            }
        }
    }

    inline char cacladd(char a){
        if(a == 0b0){return a;}
        else if(a == 0b1){return 0b01011;}
        else if(a == 0b00011){return 0b10111;}
        else if(a == 0b01011){return 0b10101;}
        else if(a == 0b00101){return 0b01111;}
        else if((a&0b10101) == 0b10101){return a;}
        return 0b0;
    }
public:
    bool escapeMaze(vector<vector<string>>& maze) {
        this->times = maze.size();
        this->n = maze[0].size();
        this->m = maze[0][0].length();
        char x;char y;
        char xx;char yy;
        char offvalue=0b0;

        vector<vector<char>>* dp = new vector<vector<char>>(n,vector<char>(m,0));
        vector<vector<char>>* dptemp = new vector<vector<char>>(n,vector<char>(m,0));
        (*dp)[0][0] = 0b1;

        for(int t = 1;t<this->times;t++){
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                    x = i;y = j;
                    if(maze[t][x][y]=='.'){
                        (*dptemp)[x][y] = (*dp)[x][y];
                        for(int o = 0; o < 4; o++){
                            xx = x + offset[o].first;
                            yy = y + offset[o].second;
                            if(xx<0||yy<0 || xx>n-1 || yy > m -1){continue;}                            
                            offvalue = (*dp)[xx][yy]&0b00111;
                            (*dptemp)[x][y] = cacl((*dptemp)[x][y],offvalue);
                        }
                    }
                    else{
                        (*dptemp)[x][y] = cacladd((*dp)[x][y]);

                        for(int o = 0; o < 4; o++){
                            xx = x + offset[o].first;
                            yy = y + offset[o].second;
                            if(xx<0||yy<0 || xx>n-1 || yy > m -1){continue;}
                            offvalue = cacladd((*dp)[xx][yy]&0b00111);

                            (*dptemp)[x][y] = cacl((*dptemp)[x][y],offvalue);
                        }
                    }
                    
                }
            }
            swap(dp,dptemp);
            if(((*dp)[n-1][m-1]&0b00001)==0b00001){return true;}
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