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
    int ret[MAXN];
public:
    void init(int n){
        this->n = n;
    }
    void setelement(int i,int x,int y){
        vn[i] = {x,y};
    }
    pair<int,int> get(int i){
        if(ret[i] == -1){return {-1,-1};}
        return vn[ret[i]];
    }
    void solve(){
        for(int i = 0; i < n; i ++){
            ret[i] = -1;
            for(int j = 0; j < n; j++){
                if(vn[i].first<vn[j].first && vn[i].second <vn[j].second){
                    if(ret[i] == -1){
                        ret[i] = j;
                    }
                    else if(vn[j].first < vn[ret[i]].first){
                        ret[i] = j;
                    }
                    else if(vn[j].first == vn[ret[i]].first && vn[j].second < vn[ret[i]].second){
                        ret[i] = j;
                    }
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