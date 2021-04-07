#include"leetcode.h"

class Solution {
private:
    int times;
    int n,m;
    char xever,yever;
    vector<pair<int,int>> offset{{0,0},{0,1},{1,0},{0,-1},{-1,0}};
    vector<char> visit;
    bool dfs(vector<vector<string>>& maze,char hasmagictemp,char index,char x,char y){
        if(n-1-x + m-1 - y > times - 1 - index){return false;}
        if(x == n - 1 && y == m - 1){
            return true;
        }
        if(index>=times-1){return false;}

        int key = (index*n*m+x*m + y)<<1;
        if(visit[key+1]==1){return false;}     
        if(visit[key+hasmagictemp]==1){return false;}
        visit[key+hasmagictemp] = 1;
        
        bool ret =false;
        char xx;char yy;
        for(char i = 0; i < 5; i ++){
            xx = x+offset[i].first;
            yy = y + offset[i].second;
            if(xx<0||yy<0||xx>n-1||yy>m-1){continue;}
            if(maze[index+1][xx][yy]=='.'){
                ret|=dfs(maze,hasmagictemp,index+1,xx,yy);
                if(ret){return ret;}
            }
            else if(xx == xever&&yy==yever){
                ret|=dfs(maze,hasmagictemp,index+1,xx,yy);
                if(ret){return ret;}
            }
            else if(hasmagictemp>0){                
                ret|=dfs(maze,hasmagictemp-1,index+1,xx,yy);
                if(ret){return ret;}                
            }
        }
                
        return ret;
    }
public:
    bool escapeMaze(vector<vector<string>>& maze) {
        this->times = maze.size();
        this->n = maze[0].size();
        this->m = maze[0][0].length();
        this->xever = 0;
        this->yever = 0;
        this->visit=vector<char>(((this->times * this->n * this->m)<<1) + 2,0);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m;j ++){
                this->xever = i;
                this->yever = j;
                this->visit.assign(((this->times * this->n * this->m)<<1) + 2,0);
                if(dfs(maze,1,0,0,0)){return true;}
            }
        }
        return false;
    }
};

// int main(){
//     vector<vector<string>> maze{

//     };

//     Solution solution;
//     auto ret = solution.escapeMaze(maze);

//     return 0;
// }