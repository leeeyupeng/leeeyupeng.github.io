#include"leetcode.h"

#define MAX 40040
class Solution {
private:
    
    int n;
    int matrix[MAX][MAX];
    int vnums;
    int addv(){return vnums++;}
    inline void addedge(int u,int v,int c){
        if(u==0||v==0){return;}
        matrix[u][v] = c;
    }

    int s,t,p;
    void buildgraph(vector<string>& grid){
        vnums = 0;        
        memset(matrix,0,sizeof(int) * MAX * MAX);
        addv();

        s = addv();
        t = addv();
        p = addv();

        int v1,v2;
        int rect[2][2][2]{{{0,0},{0,0}},{{0,0},{0,0}}};
        for(int r = 0; r<n;r++){
            for(int c = 0; c<2; c++){
                if(grid[c][r] == '#'){
                    rect[c][r&0b1][0] = 0;
                    rect[c][r&0b1][1] = 0;
                }
                else if(grid[c][r] == '.'){
                    rect[c][r&0b1][0] = addv();
                    rect[c][r&0b1][1] = addv();
                    addedge(rect[c][r&0b1][0],rect[c][r&0b1][1],1);
                }
                else{
                    rect[c][r&0b1][0] = addv();
                    rect[c][r&0b1][1] = rect[c][r&0b1][0];
                    if(grid[c][r] == 'S'){
                        addedge(s,rect[c][r&0b1][0],MAX);
                    }
                    else if(grid[c][r] == 'C'){
                        addedge(rect[c][r&0b1][1],t,MAX);
                    }
                    else if(grid[c][r] == 'P'){
                        addedge(p,rect[c][r&0b1][0],MAX);
                        addedge(rect[c][r&0b1][1],p,MAX);
                    }
                }

                addedge(rect[c][r&0b1^0b1][1],rect[c][r&0b1][0],MAX);
                addedge(rect[c][r&0b1][1],rect[c][r&0b1^0b1][0],MAX);

                if(c==1){
                    addedge(rect[c^0b1][r&0b1][1],rect[c][r&0b1][0],MAX);
                    addedge(rect[c][r&0b1][1],rect[c^0b1][r&0b1][0],MAX);
                }
            }
        }
    }

    int bfs(int s,int t,int p[]){
        for(int i = 0 ; i< vnums ;i ++){p[i] = i;}
        queue<pair<int,int>> q;
        q.push({s,MAX});
        pair<int,int> top;
        int index;
        int c;
        while(!q.empty()){
            top=q.front();
            q.pop();
            if(top.first == t){
                index = t;
                c = top.second;
                while(p[index]!=index){
                    matrix[p[index]][index] -= c;
                    matrix[index][p[index]] += c;
                    index = p[index];
                }
                return c;
            }

            for(int i = 1; i < vnums; i ++){
                if(i!= s && matrix[top.first][i] != 0 && p[i] == i){
                    p[i] = top.first;
                    q.push({i,min(top.second,matrix[top.first][i])});
                }
            }    
        }
        return 0;
    }

    int Edmonds_Karp(int s,int t){
        int ret = 0;
        int p[MAX];
        while(true){
            int delta = bfs(s,t,p);
            if(delta == 0){break;}
            ret+=delta;
        }
        return ret;
    }
public:
    int guardCastle(vector<string>& grid) {
        n = grid[0].size();
        buildgraph(grid);
        int ret = Edmonds_Karp(s,t);
        if(ret>=MAX){return -1;}
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<string> grid={"S.C.P#P.", ".....#.S"};
//     auto ret = solution.guardCastle(grid);
//     return 0;

// }