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
    int n;
    pair<int,int> vn[MAXN];
    int vnsort[MAXN];
    int ret[MAXN];
public:
    void init(int n){
        this->n = n;
        for(int i = 0; i < n; i ++){
            vnsort[i]=i;
        }
    }
    void setelement(int i,int x,int y){
        vn[i] = {x,y};
    }
    pair<int,int> get(int i){
        if(ret[i] == -1){return {-1,-1};}
        return vn[ret[i]];
    }
    void solve(){
        sort(vnsort,vnsort+n,[this](int a,int b){
            if(this->vn[a].first==this->vn[b].first){
                if(this->vn[a].second == this->vn[b].second){
                    return a<b;
                }
                return this->vn[a].second < this->vn[b].second;
            }
            return this->vn[a].first < this->vn[b].first;
        });

        int x,x1,x2;
        int y,y1,y2;
        int mid;
        for(int i = 0; i < n; i ++){
            ret[vnsort[i]] = -1;
            x = i;
            while(x<n){            
                x1 = i + 1;
                x2 = n;
                while(x1<x2){
                    mid = (x1+x2)>>1;
                    if(vn[vnsort[mid]].first <= vn[vnsort[x]].first){
                        x1 = mid+1;
                    }
                    else{
                        x2 = mid;
                    }
                }
                x = x1;
                if(x==n){break;}

                y1 = x;y2 = n;
                while(y1<y2){
                    mid = (y1+y2)>>1;
                    if(vn[vnsort[mid]].first != vn[vnsort[x]].first){
                        y2 = mid;
                    }
                    else if(vn[vnsort[mid]].second <= vn[vnsort[i]].second){
                        y1 = mid+1;
                    }
                    else{
                        y2 = mid;
                    }
                }
                y = y1;
                if(y==n){continue;}
                if(vn[vnsort[y]].first!=vn[vnsort[x]].first){continue;}
                else{
                    ret[vnsort[i]]  = vnsort[y];
                    break;
                }            
            }
        }
    }

    bool check(int a,pair<int,int> value){
        
        if(value.first!=-1 && (value.first<=vn[a].first || value.second<=vn[a].second)){
            cout<<"error"<<endl;
            return false;
        }
        for(int i = 0; i < n; i ++){
            if(vn[i].first > vn[a].first && vn[i].second > vn[a].second){
                if(value.first == -1){
                    cout<<"error"<<endl;
                    return false;
                }
                else if(vn[i].first < value.first){
                    cout<<"error"<<endl;
                    return false;
                }
                else if(vn[i].first == value.first){
                    if(vn[i].second<value.second)
                    {
                        cout<<"error"<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// int main(){
//     int casecounter = 0;
//     int n = 0;
//     int x,y;
//     pair<int,int> value;
    
//     Solution solution;
//     while(cin>>n && n > 0){
//         //n  = 1000;
//         solution.init(n);
//         for(int i = 0; i < n; i ++){
//             cin>>x>>y;
//             // x = rand() % 300;
//             // y = rand() % 300;
//             solution.setelement(i,x,y);
//         }
//         casecounter++;
//         solution.solve();
//         printf("Case %d:\n",casecounter);
//         for(int i = 0; i < n; i ++){
//             value = solution.get(i);
//             printf("%d %d\n",value.first,value.second);
//             // if(!solution.check(i,value)){
//             //     cout<<"error"<<endl;
//             // }
//         }
//         cout<<endl;
//     }
//     return 0;
// }