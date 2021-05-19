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

#define MAXN 10010
class Solution{
private:
    struct team{
        string name;
        int a;
        int t;
        int p;

        team(){}
        team(string &_name,int _a,int _t,int _p):name(_name),a(_a),t(_t),p(_p){}
    };
    int n,m;
    team arr[MAXN];
    int arrsort[MAXN];
public:
    void init(int _n,int _m){
        this->n = _n;
        this->m = _m;
    }
    void insert(int index,string _name,int _a,int _t,int _p){
        arr[index] = {_name,_a,_t,_p};
    }

    void solve(){
        for(int i = 0; i < n; i ++){
            arrsort[i] = i;
        }

        sort(arrsort,arrsort+n,[this](int a,int b){
            if(this->arr[a].t == this->arr[b].t){
                if(this->arr[a].p == this->arr[b].p){
                    return a < b;
                }
                return this->arr[a].p < this->arr[b].p;
            }
            return this->arr[a].t > this->arr[b].t;
        });

        if(arr[arrsort[m-1]].t == 0){
            m = n;
        }
        
        sort(arrsort,arrsort+m);
        bool allgirls = false;
        for(int i = 0; i < m; i ++){
            if(arr[arrsort[i]].a != 0){allgirls = true;break;}
        }
        if(allgirls== false){
            for(int i = m;i < n;i ++){
                if(arr[arrsort[i]].a != 0){
                    if(arr[arrsort[i]].t != 0) {
                        swap(arrsort[m],arrsort[i]);
                        m++;
                        break;
                    }
                }
            }
        }
        sort(arrsort,arrsort+m);

        for(int i = 0; i < m; i ++){
            cout<<arr[arrsort[i]].name<<endl;
        }
    }
};
// int main(){
//     int c;
//     cin>>c;
//     Solution solution;
//     int n,m;
//     string name;
//     int a,t,p;
//     for(int ic= 0; ic<c; ic ++){
//         cin>>n>>m;
//         solution.init(n,m);
//         for(int in = 0; in < n; in ++){
//             cin>>name>>a>>t>>p;
//             solution.insert(in,name,a,t,p);
//         }
//         printf("Case %d:\n",ic+1);
//         solution.solve();   
//         cout<<endl;     
//     }
//     return 0;
// }