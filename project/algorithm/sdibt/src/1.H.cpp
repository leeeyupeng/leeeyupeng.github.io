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

#define MAXRC 302
#define MAXN 1010
class Solution{
private:
    bool arr[MAXRC][MAXRC];
    pair<int,int> dp[MAXRC][MAXRC];
public:
    void initsolution(){
        for(int i = 0;i < MAXRC;i ++){
            dp[i][MAXRC-1] = {-1,-1};
            dp[MAXRC-1][i] = {-1,-1};
        }
    }
    void init(){
        memset(arr,0,MAXRC * MAXRC * sizeof(bool));

    }
    void setelement(int x,int y,bool value){
        arr[x][y] = value;
    }

    pair<int,int> get(int x,int y){
        return dp[x][y];
    }
    pair<int,int> cmp(pair<int,int> a,pair<int,int> b){
        if(a.first==-1){return b;}
        if(b.first==-1){return a;}
        if(a.first < b.first){
            return a;
        }
        else if(a.first == b.first){
            if(a.second <= b.second){
                return a;
            }
            else{
                return b;
            }
        }
        else{
            return b;
        }
    }
    int solve(){
        for(int i = MAXRC-2;i >=0;i--){
            for(int j = MAXRC -2;j>=0;j--){
                dp[i][j] = {-1,-1};
                if(arr[i+1][j+1]){
                    dp[i][j] = {i+1,j+1};
                    continue;
                }

                dp[i][j] = cmp(dp[i][j],dp[i+1][j]);
                dp[i][j] = cmp(dp[i][j],dp[i][j+1]);
            }
        }
    }
};
// int main(){
//     int casecounter = 0;
//     int n = 0;
//     int x,y;
//     pair<int,int> value;
    
//     Solution solution;
//     solution.initsolution();
//     vector<pair<int,int>> vn(MAXN);
//     while(cin>>n && n > 0){
//         // n  = 1000;
//         solution.init();
//         vector<pair<int,int>> vn(n);
//         for(int i = 0; i < n; i ++){
//             cin>>x>>y;
//             // x = rand() % 300;
//             // y = rand() % 300;
//             vn[i] = {x,y};
//             solution.setelement(x,y,true);
//         }
//         casecounter++;
//         solution.solve();
//         printf("Case %d:\n",casecounter);
//         for(int i = 0; i < n; i ++){
//             x = vn[i].first;
//             y = vn[i].second;
//             value = solution.get(x,y);
//             printf("%d %d\n",value.first,value.second);
//         }
//         cout<<endl;
//     }
//     return 0;
// }