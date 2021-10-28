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
                    if(grid[c][r] == 'S'){
                        rect[c][r&0b1][0] = s;
                        rect[c][r&0b1][1] = rect[c][r&0b1][0];
                        addedge(s,rect[c][r&0b1][0],MAX);
                    }
                    else if(grid[c][r] == 'C'){
                        rect[c][r&0b1][0] = t;
                        rect[c][r&0b1][1] = rect[c][r&0b1][0];
                        addedge(rect[c][r&0b1][1],t,MAX);
                    }
                    else if(grid[c][r] == 'P'){
                        rect[c][r&0b1][0] = p;
                        rect[c][r&0b1][1] = rect[c][r&0b1][0];
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
                    getedge(p[index],index)->c -= c;
                    getedge(index,p[index])->c += c;
                    index = p[index];
                }
                return c;
            }
            Edge* edge = edges[top.first];
            while(edge!=nullptr){
                if(edge->v!= s && edge->c != 0 && p[edge->v] == edge->v){
                    p[edge->v] = top.first;
                    q.push({edge->v,min(top.second,edge->c)});
                }
                edge=edge->next;
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