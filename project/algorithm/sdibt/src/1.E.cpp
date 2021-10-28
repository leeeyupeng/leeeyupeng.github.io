#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<ctime>
#if defined(linux)
#include<math.h>
#include<memory.h>
#include<limits.h>
#endif
using namespace std;

#define MAXN 310
class Solution{
private:
    int n;
    bool recaptured[MAXN];
    int matrix[MAXN][MAXN];
    int dp[MAXN][MAXN];
public:
    void init(int n){
        this->n = n;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                matrix[i][j] = INT_MAX;
                dp[i][j] = INT_MAX;
            }
        }
        for(int i = 0; i < n; i ++){
            recaptured[i] = false;
            matrix[i][i] = 0;
            dp[i][i] = 0;
        }
    }

    void addedge(int x,int y,int z){
        matrix[x][y] = min(matrix[x][y],z);
    }

    void addrecaptured(int x){
        recaptured[x] = true;
        for(int k = 0; k < n; k ++){
            if(recaptured[k]==false){continue;}
            if(dp[k][x] > matrix[k][x]){
                for(int i = 0; i < n; i ++){
                    if(recaptured[i]==false){continue;}
                    for(int j = 0; j < n; j ++){
                        if(recaptured[j]==false){continue;}
                        if(matrix[k][x]!=INT_MAX && dp[i][k] != INT_MAX && dp[x][j]!=INT_MAX){
                            dp[i][j] = min(dp[i][j],dp[i][k]+matrix[k][x] + dp[x][j]);
                        }
                    }
                }
            }

            if(dp[x][k] > matrix[x][k]){
                for(int i = 0; i < n; i ++){
                    if(recaptured[i]==false){continue;}
                    for(int j = 0; j < n; j ++){
                        if(recaptured[j]==false){continue;}
                        if(matrix[x][k]!=INT_MAX && dp[i][x] != INT_MAX && dp[k][j]!=INT_MAX){
                            dp[i][j] = min(dp[i][j],dp[i][x]+matrix[x][k] + dp[k][j]);
                        }
                    }
                }
            }
        }
        
    }

    bool isrecaptured(int x){
        return recaptured[x];
    }

    int shortestpath(int x,int y){
        return dp[x][y];
    }

};
// int main(){
//     int casecounter = 0;
//     int n = 0,m,q;
//     int x,y,z;
//     int oper;
//     Solution solution;
//     while(cin>>n>>m>>q && n > 0){
//         // n = 300;
//         // m = 100000;
//         // q = 100000;
//         casecounter++;
//         solution.init(n);
//         for(int i = 0; i < m; i ++){
//             scanf("%d%d%d",&x,&y,&z);
//             // x = rand()%n;
//             // y = rand()%n;
//             // z = rand()%10000;
//             solution.addedge(x,y,z);
//         }
//         printf("Case %d:\n",casecounter);
//         for(int i = 0; i < q; i ++){
//             scanf("%d%d",&oper,&x);
//             // oper = rand() % 2;
//             // x = rand()%n;
//             if(oper==0){
//                 if(solution.isrecaptured(x)){
//                     printf("City %d is already recaptured.\n",x);
//                 }
//                 else{
                    
//                     solution.addrecaptured(x);
//                 }
//             }
//             else if(oper == 1){
//                 scanf("%d",&y);
//                 // y = rand()%n;
//                 if(solution.isrecaptured(x) && solution.isrecaptured(y)){
//                     auto ret = solution.shortestpath(x,y);
//                     if(ret == INT_MAX){
//                         printf("No such path.\n");
//                     }
//                     else{
//                         printf("%d\n",ret);
//                     }
//                 }
//                 else{
//                     printf("City %d or %d is not available.\n",x,y);
//                 }
//             }
//         }
//         printf("\n");
//     } 
//     return 0;
// }