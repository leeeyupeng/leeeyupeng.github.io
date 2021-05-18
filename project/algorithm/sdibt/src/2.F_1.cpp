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
#define MAXD 6
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
    inline int getsums(int a[],int dd){
        int sums = 0;
        for(int i = 0; i < d;i ++){
            if(((dd>>i)&0x1)==0x0){
                sums += a[i];
            }
            else{
                sums -= a[i];
            }
        }
        return sums;
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
        {
            pair<int,int> minmax[1<<MAXD];
            int value=0;
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < (1<<d);j++){
                    value = getsums(arr[i],j);
                    if(i==0){minmax[j]={value,value};}
                    else{
                        minmax[j].first = max(minmax[j].first,value);
                        minmax[j].second = min(minmax[j].second,value);
                    }
                }
            }

            int ret = 0;
            for(int j = 0; j < (1<<d);j ++){
                ret = max(ret,minmax[j].first - minmax[j].second);
            }
            return ret;
        }
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