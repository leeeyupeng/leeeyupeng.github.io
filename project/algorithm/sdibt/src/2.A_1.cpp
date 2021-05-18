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
    //int arr[MAXN];
    int onenumscounter;
    int twonumscounter;
    pair<int,int> offset[15]{
        {0,-1},{0,-2},{0,-3},
        {-1,0},{-1,-1},{-1,-2},
        {-2,0},{-2,-1},
        {-3,0},
        {1,-1},{1,-2},{1,-3},
        {2,-2},{2,-3},
        {3,-3}
    };

    pair<int,int> offset1[3]{
        {-3,0},{-2,0},{-1,0}
    };

    pair<int,int> offset2[12]{
        {0,-1},{0,-2},{0,-3},{1,-3},{2,-3},{3,-3},{-1,-2},{1,-2},{2,-2},
        {-1,-1},
        {-2,-1},        
        {1,-1},
    };

    unordered_map<int,bool> um1;
    unordered_map<int,bool> um2;
    bool dfs1(int onenums){
        int key = onenums;
        if(um1.find(key)!=um1.end()){
            return um1[key];
        }
        bool ret = false;
        int o,t;
        for(int i = 0; i < 3;i++){
            o = onenums+offset1[i].first;
            //t = twonums+offset1[i].second;
            if(o>=0){
                ret |= !dfs1(o);
                if(ret){break;}
            }
        }
        um1[key] = ret;
        return ret;
    }
    bool dfs2(int onenums,int twonums){
        int key = onenums * (n) + twonums;
        if(um2.find(key)!=um2.end()){
            return um2[key];
        }
        bool ret = false;
        int o,t;
        
        for(int i = 0; i < 12; i ++){
            o = onenums+offset2[i].first;
            t = twonums+offset2[i].second;
            if(o>=0 &&t >=0){
                if(t==0){
                    ret|=dfs1(o);
                }
                else{
                    ret |= !dfs2(o,t);
                }
            }
            if(ret){break;}
        }   
        um2[key] = ret;
        return ret;
    }
public:
    inline void init(int n){
        this->n = n;
        //memset(arr,0,sizeof(int) * this->n);

        onenumscounter = 0;
        twonumscounter = 0;

        //memset(visit,0,sizeof(char) * this->n * this->n);
        //um.clear();
        // um1.clear();
        // um2.clear();

        // sort(offset2,offset2+12,[](pair<int,int> &a,pair<int,int> &b){
        //     if(a.first + a.second == b.first + b.second){
        //         return a.second<b.second;
        //     }
        //     return a.first + a.second < b.first + b.second;
        // });
    }

    inline void add(int index,int value){
        //arr[index] = value==1?1:2;
        if(value == 1){
            onenumscounter++;
        }
        else{
            twonumscounter++;
        }
    }

    bool solve(){
        if(twonumscounter==0){
            return dfs1(onenumscounter);
        }
        else{
            return dfs2(onenumscounter,twonumscounter);
        }
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
//         //n = rand()%10000;
//         solution.init(n);
//         for(int j = 0; j < n; j ++){
//             //cin>>value;
//             value = rand()%2 + 1;
//             solution.add(j,value);
//         }

//         auto ret = solution.solve();
//         cout<<(ret?"Yes":"No")<<endl;
//     }
//     return 0;
// }