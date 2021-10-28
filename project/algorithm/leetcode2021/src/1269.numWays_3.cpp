#include"leetcode.h"


class Solution {
private:
    int len;
    long long ret = 0;
    int visit[500][500];
    int dfs(int steps,int loc){
        if(loc>steps){return 0;}
        if(loc==steps){return 1;}
        if(steps==0){
            if(loc == 0){return 1;}
            return 0;
        }
        if(visit[steps][loc]!=-1){return visit[steps][loc];}
        long long ret=0;
        ret+=dfs(steps-1,loc);
        if(loc-1>=0){
            ret+=dfs(steps-1,loc-1);
        }
        if(loc+1<=len){
            ret+=dfs(steps-1,loc+1);
        }
        ret%=1000000007;
        visit[steps][loc] = ret;
        return ret;
    }
public:
    int numWays(int steps, int arrLen) {
        len = min(steps >>1,arrLen-1);
        ret = 0;
        for(int i = 0; i < 500;i++){
            for(int j = 0; j < 500;j++){
                visit[i][j] = -1;
            }
        }
        return dfs(steps,0);
    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.numWays(60,3);
    
//     return 0;

// }