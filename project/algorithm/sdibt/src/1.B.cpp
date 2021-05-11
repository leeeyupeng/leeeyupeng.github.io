#include <iostream>
#include <vector>
#include<string>
using namespace std;


#define MAXN 102
class Solution{
private:
    int us[MAXN * MAXN];
    int find(int index){
        if(us[index] != index){
            us[index] = find(us[index]);
        }
        return us[index];
    }
public:
    int getblocks(int n,char matrix[MAXN][MAXN],vector<pair<int,int>> &offset){
        for(int i = 0; i < n*n; i ++){
            us[i] = i;
        }
        int offsetn = offset.size();
        pair<int,int> temp;
        int ijk,tempk;
        int ijp,tempp;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(matrix[i][j] == '1'){
                    ijk = i * n + j;                    
                    for(int o = 0; o < offsetn;o++){
                        temp = {i+offset[o].first,j + offset[o].second};
                        if(temp.first>=0 && temp.first < n && temp.second>=0 && temp.second <n){
                            if(matrix[temp.first][temp.second] == '1'){
                                tempk = temp.first * n + temp.second;
                                ijp = find(ijk);
                                tempp = find(tempk);
                                if(ijp != tempp){
                                    us[tempp] = ijp;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(matrix[i][j] == '1'){
                    ijk = i * n + j;
                    if(us[ijk] == ijk){ret++;}
                }
            }
        }
        return ret;
    }
};

// int main(){
//     int testn = 0;
//     int n = 0;   
//     char matrix[MAXN][MAXN]; 
//     vector<pair<int,int>> offsetsaya{{1,0},{0,1}};
//     vector<pair<int,int>> offsetkudo{{1,-1},{1,0},{0,1},{1,1}};
//     Solution solution;
//     while(cin>>n && n > 0){
//         for(int i = 0; i < n; i ++){
//             for(int j = 0; j < n; j ++){
//                 cin>>matrix[i][j];
//             }
//         }
//         auto retsaya = solution.getblocks(n,matrix,offsetsaya);
//         auto retkudo = solution.getblocks(n,matrix,offsetkudo);
//         testn++;
//         printf("Case %d: %d %d\n",testn,retsaya,retkudo);
//         printf("\n");
//     }
//     return 0;
// }