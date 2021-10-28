#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>

#include <stdio.h>

using namespace std;

#define MAXVN 2010

class Solution{
public:
    bool isbipartitegraph(int n,char matrix[MAXVN][MAXVN]){
        char visit[MAXVN];
        memset(visit,0,sizeof(char) * MAXVN);
        int i,j;
        int start = 1;
        queue<int> q;
        while(true){
            while(start<=n){
                if(visit[start]==0){break;}
                start++;
            }
            if(start == n+1){break;}
            q.push(start);
            visit[start] = 1;
            while(!q.empty()){
                i = q.front();
                q.pop();
                for(j = 1;j<=n;j++){
                    if(matrix[i][j]==1){
                        if(visit[j]==0){
                            visit[j] = ~visit[i];
                            q.push(j);
                        }
                        else if(visit[j] == visit[i]){
                            return false;
                        }
                        else{

                        }
                    }
                }
            }
        }

        return true;
    }
};
// int main(){
//     int testcases;
//     scanf("%d",&testcases);
//     int vn,en;
//     int u,v;
//     char matrix[MAXVN][MAXVN];

//     Solution solution;
//     for(int c = 0;c < testcases; c ++){
//         scanf("%d%d",&vn,&en);
//         memset(matrix,0,sizeof(char) * MAXVN * MAXVN);
//         for(int i = 0; i < en;i++){
//             scanf("%d%d",&u,&v);
//             matrix[u][v] = 1;
//             matrix[v][u] = 1;
//         }

//         if(solution.isbipartitegraph(vn,matrix)){
//             printf("Scenario #%d:\nNo suspicious bugs found!\n",c+1);            
//         }
//         else{
//             printf("Scenario #%d:\nSuspicious bugs found!\n",c+1);
//         }
//         printf("\n");
//     }

//     return 0;
// }