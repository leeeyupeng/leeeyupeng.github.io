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
    pair<int,int> visit[MAXN << 1];
    bool dfs(int onenums,int twonums){
        //if(visit[onenums].first!= -1 && visit[onenums].first <= twonums){return true;}
        //if(visit[onenums].second!= -1 && visit[onenums].second >= twonums){return false;}
        bool ret = false;
        if(twonums == 0){
            for(int i = min(3,onenums); i >= 1; i --){
                ret|= !dfs(onenums - i,twonums);
                if(ret){break;}
            }
        }
        else{
            for(int j = min(3,twonums);j>=1;j--){
                for(int i = min((j << 1) + 3-j,min(3,onenums));i>=max(j,1);i--){
                    if(onenums - i < twonums - j){continue;}
                    ret|= !dfs(onenums - i,twonums - j);
                    if(ret){break;}
                }
                if(ret){break;}
            }
        }

        if(ret){
            visit[onenums].first = twonums;
        }
        else{
            visit[onenums].second = twonums;
        }

        return ret;
    }
public:
    inline void init(int n){
        this->n = n;
        onenumscounter = 0;
        twonumscounter = 0;

        memset(visit,-1,sizeof(pair<int,int>) * ((this->n <<1) + 1));
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
        return dfs(onenumscounter%72 + ((twonumscounter%72) <<1),twonumscounter%72);
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