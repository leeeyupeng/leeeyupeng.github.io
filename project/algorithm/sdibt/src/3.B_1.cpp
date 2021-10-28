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
    long long maxprofits;
    //long long dp[100*100*100 * 30*3];
    pair<int,int> kinds[KINDN+1];
    int sortkinds[KINDN+1];
    int lcm(int a,int b){
        if(a<b){swap(a,b);}
        return a * b / gcd(a,b);
    }
    int gcd(int a,int b){        
        if(b==0){return a;}
        return gcd(b,a%b);
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
        
        long long gbs = lcm(kinds[0].first,kinds[1].first);
        gbs = lcm(gbs,kinds[2].first);
        // long long gbs=kinds[0].first*kinds[1].first*kinds[2].first;
        long long vv = v;
        if(v>gbs*2){
            maxprofits=(v/gbs-2) * gbs / kinds[sortkinds[0]].first * kinds[sortkinds[0]].second;
            vv = v % gbs + gbs * 2;
        }
        vector<long long> dp(vv+1,0);
        for(int i = 0; i <= vv;i++){
            dp[i] = 0;
        }
        for(int j = 0; j < KINDN;j++){
            for(int i = kinds[j].first;i <= vv; i ++){
                dp[i] = max(dp[i],dp[i-kinds[j].first] + kinds[j].second);
            }
        }
        
        maxprofits+= dp[vv];

        return maxprofits;
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