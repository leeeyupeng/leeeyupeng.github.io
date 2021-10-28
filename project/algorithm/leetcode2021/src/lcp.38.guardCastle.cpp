#include"leetcode.h"

#define MAX 20010
class Solution {
private:
    struct  Edge
    {
        int v;
        int c;
        Edge* next;
        Edge():next(nullptr){}
    };
    
    int n;

    vector<Edge*> edges;
    int vnums;
    int addv(){edges.push_back(nullptr);return vnums++;}
    void addedge(int u,int v,int c){
        if(u==0||v==0){return;}
        Edge* edge = new Edge();
        edge->v = v;
        edge->c = c;
        edge->next = edges[u];
        edges[u] = edge;

        // edge = new Edge();
        // edge->v = u;
        // edge->c = 0;
        // edge->next = edges[v];
        // edges[v]=edge;
    }

    Edge* getedge(int u,int v){
        Edge* edge = edges[u];
        while(edge!=nullptr){
            if(edge->v == v){return edge;}
            edge=edge->next;
        }
        edge = new Edge();
        edge->v = v;
        edge->c = 0;
        edge->next = edges[u];
        edges[u] = edge;
        return edge;
    }
    int s,t,p;
    void buildgraph(vector<string>& grid){
        vnums = 0;        
        edges.clear();
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

    int dfs(int u,int t,int val,vector<char> &visit){
        visit[u] = 1;
        if(u == t){return val;}
        Edge* edge = edges[u];
        while(edge!=nullptr){
            if(edge->c!=0 && visit[edge->v] == 0){
                int vval = dfs(edge->v,t,min(val,edge->c),visit);
                if(vval!=0){
                    edge->c -= vval;
                    getedge(edge->v,u)->c += vval;
                    return vval;
                }
            }
            edge = edge->next;
        }
        return 0;
    }
    int ford_fulkerson(int s,int t){
        vector<char> visit(vnums,0);
        int ret = 0;
        while(true){
            for(int i = 0; i < vnums; i ++){visit[i] = 0;}
            int delta = dfs(s,t,MAX,visit);
            if(delta == 0){break;}
            ret+=delta;
        }
        return ret;
    }
public:
    int guardCastle(vector<string>& grid) {
        n = grid[0].size();
        buildgraph(grid);
        int ret = ford_fulkerson(s,t);
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