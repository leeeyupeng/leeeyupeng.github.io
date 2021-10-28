#include <iostream>
#include <vector>
#include<string>
using namespace std;

#define MAXN 305
class Solution{
private:
    bool isclockwise(pair<int,int> a,pair<int,int> b){
        int abcross = a.first*b.second - a.second * b.first;
        if(abcross!=0){return abcross>0;}
        else{
            if(a.first*b.first + a.second+b.second > 0){return true;}
        }
        return false;
    }

    bool iscounterclockwise(pair<int,int> a,pair<int,int> b){
        int abcross = a.first*b.second - a.second * b.first;
        if(abcross!=0){return abcross<0;}
        else{
            if(a.first*b.first + a.second+b.second < 0){return true;}
        }
        return false;
    }
public:
    void Solve(int n,pair<int,int> vec[MAXN]){
        int ret = -1;
        bool dir = true;

        int dp[MAXN][MAXN];
        int cret=0;
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
                dp[i][j]=1;
                for(int k = 0; k < i; k++){
                    if(isclockwise({vec[j].first - vec[i].first,vec[j].second - vec[i].second},{vec[i].first - vec[k].first,vec[i].second - vec[k].second})){
                        dp[i][j] = max(dp[i][j],dp[k][i]+1);
                    }
                }
                cret = max(cret,dp[i][j]);
            }
        }
        int ccret = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
                dp[i][j]=1;
                for(int k = 0; k < i; k++){
                    if(iscounterclockwise({vec[j].first - vec[i].first,vec[j].second - vec[i].second},{vec[i].first - vec[k].first,vec[i].second - vec[k].second})){
                        dp[i][j] = max(dp[i][j],dp[k][i]+1);
                    }
                }
                ccret = max(ccret,dp[i][j]);
            }
        }
        if(cret>=ccret){
            if(cret + 1 == n){
                cout<<"C"<<endl;
            }
            else{
               printf("Remove %d bead(s), %s\n",n-(cret+1),"C"); 
            }
        }
        else{
            if(ccret + 1 == n){
                cout<<"CC"<<endl;
            }
            else{
               printf("Remove %d bead(s), %s\n",n-(ccret+1),"CC"); 
            }
        }
        cout<<endl;
    }
};

// int main(){
//     int n = 0;  
//     pair<int,int> vec[MAXN];
//     Solution solution;
//     while(cin>>n && n > 0){
//         for(int i = 0; i < n; i ++){
//             cin>>vec[i].first>>vec[i].second;
//         }

//         solution.Solve(n,vec);
//     } 
//     return 0;
// }