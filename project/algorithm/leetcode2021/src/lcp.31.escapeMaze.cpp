#include"leetcode.h"

class Solution {
private:
    int times;
    int n,m;
    int xever,yever;
    vector<pair<int,int>> offset{{0,0},{0,1},{1,0},{0,-1},{-1,0}};
    vector<char> visit;
    bool dfs(vector<vector<string>>& maze,int hasmagictemp,int hasmagicever,int index,int x,int y){
        if(n-1-x + m-1 - y > times - 1 - index){return false;}
        if(x == n - 1 && y == m - 1){
            return true;
        }
        if(index>=times-1){return false;}

        int key = ((index*n*m*n*m+x*m*n*m + y*n*m + (0) * m + (0))<<2) + (1<<1) + 1;
        if(visit[key]==1){return false;}
        key = ((index*n*m*n*m+x*m*n*m + y*n*m + (xever) * m + (yever))<<2) + (hasmagictemp<<1) + hasmagicever;        
        if(visit[key]==1){return false;}
        visit[key] = 1;
        
        bool ret =false;
        int xx;int yy;
        for(int i = 0; i < 5; i ++){
            xx = x+offset[i].first;
            yy = y + offset[i].second;
            if(xx<0||yy<0||xx>n-1||yy>m-1){continue;}
            if(maze[index+1][xx][yy]=='.'){
                ret|=dfs(maze,hasmagictemp,hasmagicever,index+1,xx,yy);
                if(ret){return ret;}
            }
            else if(xx == xever&&yy==yever){
                ret|=dfs(maze,hasmagictemp,hasmagicever,index+1,xx,yy);
                if(ret){return ret;}
            }
            else{
                if(hasmagicever>0){
                    xever = xx,yever =yy;
                    ret|=dfs(maze,hasmagictemp,hasmagicever-1,index+1,xx,yy);
                    xever = 0,yever =0;
                    if(ret){return ret;}
                }
                if(hasmagictemp>0){
                    ret|=dfs(maze,hasmagictemp-1,hasmagicever,index+1,xx,yy);
                    if(ret){return ret;}
                }
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
        this->visit=vector<char>(((this->times * this->n * this->m * this->n * this->m)<<2) + 4,0);
        return dfs(maze,1,1,0,0,0);
    }
};

// int main(){
//     vector<vector<string>> maze{
// {".##..####",".#######."},{"..######.","########."},{".#####.##",".#######."},{".#..###.#","########."},{".########","########."},{".######.#","####.###."},{".#####.##","#####.#.."},{".##.####.","##.#####."},{".########","#####.##."},{".#.######","#.##.###."},{".########","###.#.#.."},{".########","########."},{".####.##.","##.##...."},{".#######.","###.#.##."},{".####.###","###.####."},{".######.#","##.####.."},{".##.#####","##.###.#."},{".####.###","##.#####."},{".##.##..#",".#.#####."},{".###.####","##.#..##."},{".####.#.#","##.#####."},{".####.###","####.###."},{".########","#######.."},{".#####.##","#.######."},{".########","###..#.#."},{".####.#.#","###..##.."},{".######.#","########."},{".########","##.#####."},{".########","..######."},{".#####..#","#######.."},{".#.######",".#######."},{".###.#.#.",".##..#.#."},{".#.##.###","####.##.."}
   
//     };

//     Solution solution;
//     auto ret = solution.escapeMaze(maze);

//     return 0;
// }