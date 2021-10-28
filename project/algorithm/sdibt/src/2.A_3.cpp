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
    int n;
    int onenumscounter;
    int twonumscounter;
    pair<int,int> offset[15]{
        {0,-3},{1,-3},{2,-3},{3,-3},
        {-1,-2},{0,-2},{1,-2},{2,-2},
        {-2,-1},{-1,-1},{0,-1},{1,-1},
        {-3,0},{-2,0},{-1,0}
    };

    unordered_map<int,bool> um;
    bool dfs(int onenums,int twonums){
        onenums = onenums & 0x3;
        //if(twonums == 0 && onenums == 0){return true;}
        int key = onenums * (n) + twonums;
        if(um.find(key)!=um.end()){
            return um[key];
        }
        bool ret = false;
        int o,t;
        for(int i = 0; i < 15;i++){
            o = onenums+offset[i].first;
            t = twonums+offset[i].second;
            if(o>=0 &&t >=0){
                ret |= !dfs(o,t);
                if(ret){break;}
            }
        }
        um[key] = ret;
        return ret;
    }
public:
    inline void init(int n){
        this->n = n;
        //memset(arr,0,sizeof(int) * this->n);

        onenumscounter = 0;
        twonumscounter = 0;

        //memset(visit,0,sizeof(char) * this->n * this->n);
        um.clear();

        // sort(offset,offset+15,[](pair<int,int> &a,pair<int,int> &b){
        //     if(a.first + a.second == b.first + b.second){
        //         return a.second<b.second;
        //     }
        //     return a.first + a.second < b.first + b.second;
        // });
    }

    inline void add(int index,int value){
        if(value == 1){
            onenumscounter++;
        }
        else{
            twonumscounter++;
        }
    }

    bool solve(){
        return dfs(onenumscounter,twonumscounter);
    }
};

// int main(){
//     int testcases;
//     cin>>testcases;
//     Solution solution;
//     int n;
//     int value;
//     for(int i = 0; i<testcases; i ++){
//         cin>>n;
//         //n = rand() % 1000;
//         solution.init(n);
//         for(int j = 0; j < n; j ++){
//             cin>>value;
//             //value =  1;
//             solution.add(j,value);
//         }

//         auto ret = solution.solve();
//         cout<<(ret?"Yes":"No")<<endl;
//     }
//     return 0;
// }