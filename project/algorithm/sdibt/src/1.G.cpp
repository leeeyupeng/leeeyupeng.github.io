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

#define MAXN 1010
class Solution{
private:
    int n,m;
    int arr[MAXN];
    long long GN;
    void dfs(long long value,int nums,int start){
        GN = max(GN,value);
        if(nums == 0){
            return;
        }
        if(GN == m){return;}
        if(start!=0&&arr[start] == arr[start-1]){return;}
        if(value + (long long)nums * (long long) arr[start] <= GN){return ;}
        int a = start,b = n;
        int mid;
        while(a<b){
            mid = (a+b)>>1;
            if((long long)arr[mid]+value > m){
                a = mid+1;
            }
            else{
                b = mid;
            }
        }
        for(int i = a; i < n; i ++){
            dfs(value + arr[i],nums-1,i);
        }
    }
public:
    void init(int n,int m){
        this->n = n;
        this->m = m;
        this->GN = 0;
    }
    void setelement(int i,int value){
        arr[i] = value;
    }

    int solve(){
        sort(arr,arr+n,greater<int>());
        dfs(0,4,0);
        return this->GN;
    }
};
// int main(){
//     int casecounter = 0;
//     int n = 0;
//     int m;
//     int value;
//     Solution solution;
//     while(cin>>n>>m && n > 0){
//         // n = 1000;
//         // m = 10000000;
//         solution.init(n,m);
//         for(int i = 0; i < n; i ++){
//             cin>>value;
//             //value = rand()%10000000;
//             solution.setelement(i,value);
//         }
//         casecounter++;
//         printf("Case %d: %d",casecounter,solution.solve());
//         cout<<endl;
//     }
//     return 0;
// }