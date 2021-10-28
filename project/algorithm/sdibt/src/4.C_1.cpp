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
#define LEN 35000
class Solution{
private:
    int dppower1[LEN];
    int dppower2[LEN];
    int len;
    void init(int n, int A, int K, int a, int b, int m, int P){
        dppower1[0] = 1;
        for(int i = 1; i <= len; i ++){
            dppower1[i] = ((long long)dppower1[i-1] * (long long)A) % (long long)P;
        }
        long long dplen = ((long long)dppower1[len]) % (long long)P;
        dppower2[0] = 1;
        for(int i = 1;i <= len; i ++){
            dppower2[i] = ((long long)dppower2[i-1] * (long long)dplen) % (long long)P;
        }
    }
public:
    int solve(int n, int A, int K, int a, int b, int m, int P){
        len = sqrt(max(K,m)) + 1;
        init(n, A, K, a, b, m, P);
        long long ret = 0;
        long long fx = K;
        for(int i = 1; i <= n; i++){
            ret += ((long long)dppower1[fx%len] * (long long)dppower2[fx/len]) % (long long)P;
            ret%=P;
            fx = (a*fx + b)%m;
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