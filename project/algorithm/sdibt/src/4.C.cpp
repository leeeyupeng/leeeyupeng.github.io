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

#define MAXN 1000100
class Solution{
private:
    int dpfx[MAXN];
    int dppower[32];
    void init(int n, int A, int K, int a, int b, int m, int P){
        long long bit = A;
        for(int i = 1; i < 32; i ++){
            dppower[i] = bit;
            bit = bit * bit;
            bit %= P;
        }
        dpfx[0] = -1;
        dpfx[1] = K;;
        for(int i = 2; i <= n; i ++){
            dpfx[i] = ((long long)a*(long long)dpfx[i-1] + b)%m;
        }

        sort(dpfx,dpfx + n+1);
    }
    int power(int x,int y,int p){
        long long bit = x;
        long long ret = 1;
        int index = 1;
        while(y!=0){
            if((y & 0x1) == 0x1){
                ret *= dppower[index];
                ret %= p;
            }
            index ++;
            y >>=1;
        }
        return ret;
    }
public:
    int solve(int n, int A, int K, int a, int b, int m, int P){
        init(n, A, K, a, b, m, P);
        long long ret = 0;
        long long last = 0;
        for(int i = 1; i <= n; i++){
            if(dpfx[i-1] == dpfx[i]){
            }
            else{
                last = power(A,dpfx[i],P);
            }
            ret += last;
            //ret %= P;
        }
        ret%=P;
        return ret;
    }
};

// int main(){
//     int t;
//     cin>>t;
//     Solution solution;
//     int n, A, K, a, b, m, P;
//     for(int it = 0; it<t; it ++){
//         cin>>n>>A>>K>>a>>b>>m>>P;

//         auto ret = solution.solve(n, A, K, a, b, m, P);
//         printf("Case #%d: %d\n",it+1,ret);
//     }
//     return 0;
// }