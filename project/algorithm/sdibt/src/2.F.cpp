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

#define MAXN 100010
#define MAXD 5
class Solution{
    
private:
    int n,d;
    int arr[MAXN][MAXD];
    inline int distance(int a[],int b[]){
        int ret = 0;
        for(int i = 0; i < d; i ++){
            ret += abs(a[i] - b[i]);
        }
        return ret;
    }
public:
    void init(int _n,int _d){
        this->n = _n;
        this->d = _d;
    }
    void insert(int nindex,int dindex,int value){
        arr[nindex][dindex] = value;
    }

    int solve(){
        int ret = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
                ret = max(ret,distance(arr[i],arr[j]));
            }
        }
        return ret;
    }
};
// int main(){
//     int testcases;
//     cin>>testcases;
//     Solution solution;
//     int n;
//     int d;
//     int value;
//     for(int i = 0; i<testcases; i ++){
//         cin>>n>>d;
//         solution.init(n,d);
//         for(int j = 0; j < n; j ++){
//             for(int id = 0; id < d; id ++){
//                 cin>>value;
//                 solution.insert(j,id,value);
//             }
//         }

//         auto ret = solution.solve();
//         cout<<ret<<endl;
//     }
//     return 0;
// }