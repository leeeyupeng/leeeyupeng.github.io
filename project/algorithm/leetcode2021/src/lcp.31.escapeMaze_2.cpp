#include"leetcode.h"

class Solution {
private:
    int times;
    int n,m;
    vector<pair<int,int>> offset{{0,0},{0,1},{1,0},{0,-1},{-1,0}};
    vector<char> visit;
    bool dfs(vector<vector<string>>& maze,char index,char x,char y,char p1,char p2){
        if(n-1-x + m-1 - y > times - 1 - index){return false;}
        if(x == n - 1 && y == m - 1){
            return true;
        }
        if(index>=times-1){return false;}

        int key = (index*n*m + x * m + y)<<4;
        key += (p1<<2) + p2;
        if(visit[key]==1){return false;}  
        visit[key] = 1;
        
        bool ret =false;
        int xx;int yy;
        for(int i = 0; i < 5; i ++){
            xx = x+offset[i].first;
            yy = y + offset[i].second;
            if(xx<0||yy<0||xx>n-1||yy>m-1){continue;}
            if(maze[index+1][xx][yy]=='.'){
                ret|=dfs(maze,index+1,xx,yy,p1,i==0?p2:min((char)1,p2));
                if(ret){return ret;}
            }
            else{
                if(p2 == 2 && i == 0){
                    ret|=dfs(maze,index+1,xx,yy,p1,p2);
                    if(ret){return ret;}
                }
                else if(p1==0){
                    ret|=dfs(maze,index+1,xx,yy,1,i==0?p2:min((char)1,p2));
                    if(ret){return ret;}
                }
                if(p2 == 0){
                    ret|=dfs(maze,index+1,xx,yy,p1,2);
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
        this->visit=vector<char>(((this->times * this->n * this->m)<<4) + 16,0);
        return dfs(maze,0,0,0,0,0);
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