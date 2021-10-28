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

#define KINDN 3
class Solution{
private:
    int lcm(int a,int b){
        if(a<b){swap(a,b);}
        return a * b / gcd(a,b);
    }
    int gcd(int a,int b){        
        if(b==0){return a;}
        return gcd(b,a%b);
    }
    long long maxprofits;
    pair<int,int> kinds[KINDN+1];
    int sortkinds[KINDN+1];
    void dfs(int v,long long profits,int index){
        if(index == KINDN){maxprofits = max(maxprofits,profits);return;}
        pair<int,int> kind = kinds[sortkinds[index]];
        long long pp;
        int vv;
        long long ppp;
        for(int i = v/kind.first; i >= 0; i --){
            pp = profits+kind.second * i;
            vv = v - kind.first * i;
            ppp = pp+ceil((double)1.0f * vv*kinds[sortkinds[index+1]].second/kinds[sortkinds[index+1]].first);
            if(maxprofits == 0 || ppp>maxprofits){
                dfs(vv,pp,index+1);
            }
            else{
                break;
            }
        }
    }
public:
    void insert(int index,pair<int,int> k){
        kinds[index] = k;
    }
    long long solve(int v){
        kinds[KINDN] = {1,0};
        for(int i =0; i <= KINDN;i ++){
            sortkinds[i] = i;
        }

        sort(sortkinds,sortkinds+KINDN,[this](int a,int b){
            if(this->kinds[a].second * this->kinds[b].first == this->kinds[b].second * this->kinds[a].first){
                if(this->kinds[a].first == this->kinds[b].first){
                    return a<b;
                } 
                return this->kinds[a].first > this->kinds[b].first;
            }
            return this->kinds[a].second * this->kinds[b].first > this->kinds[b].second * this->kinds[a].first;
        });
        maxprofits=0;
        long long ret=0;
        long long gbs = lcm(kinds[0].first,kinds[1].first);
        gbs = lcm(gbs,kinds[2].first);
        // long long gbs=kinds[0].first*kinds[1].first*kinds[2].first;
        int vv = v;
        if(v>gbs*2){
            ret=(v/gbs-2) * gbs / kinds[sortkinds[0]].first * kinds[sortkinds[0]].second;
            vv = v % gbs + gbs * 2;
        }

        dfs(vv,0,0);

        return ret+maxprofits;
    }
};
// int main(){
//     int t;
//     cin>>t;
//     Solution solution;
//     int s;
//     int p;
//     int v;
//     int value;
//     pair<int,int> kind;
//     for(int it = 0; it<t; it ++){
//         for(int i = 0; i < KINDN; i ++){
//             cin>>kind.first>>kind.second;
//             solution.insert(i,kind);
//         }

//         cin>>v;

//         auto ret = solution.solve(v);
//         printf("Case %d: %lld\n",it+1,ret);
//     }
//     return 0;
// }