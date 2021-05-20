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


#define MAXNM 21
class Solution{
private:
    int n,m;
    int matrix[MAXNM][MAXNM];
    pair<int,int> offset[4]{{-1,0},{1,0},{0,-1},{0,1}};
public:
    void init(int _n,int _m){
        n = _n;
        m = _m;
    }
    void insert(int i,int j,int value){
        matrix[i][j] = value;
    }

    pair<int,pair<int,int>>  solve(){
        pair<int,pair<int,int>> ret = {INT_MIN,{0,0}};
        int value = 0;
        pair<int,int> adjacent;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                value = 0;
                for(int o = 0; o < 4;o++){
                    adjacent = {i+offset[o].first,j + offset[o].second};
                    if(adjacent.first < 0 || adjacent.first >= n || adjacent.second < 0 || adjacent.second >= m){
                        value --;
                    }
                    else{
                        value += matrix[adjacent.first][adjacent.second] - matrix[i][j];
                    }
                }

                if(value >= ret.first){
                    ret={value,{i,j}};
                }
            }
        }

        return ret;
    }
};
// int main(){
//     int t;
//     cin>>t;
//     Solution solution;
//     int n;
//     int m;
//     int value;
//     pair<int,int> kind;
//     for(int it = 0; it<t; it ++){
//         cin>>n>>m;
//         solution.init(n,m);
//         for(int in = 0; in < n; in ++){
//             for(int im=0;im<m;im++){
//                 cin>>value;
//                 solution.insert(in,im,value);
//             }
//         }

//         auto ret = solution.solve();
//         printf("Case %d: %d %d %d\n",it+1,ret.first,ret.second.first + 1,ret.second.second + 1);
//     }
//     return 0;
// }