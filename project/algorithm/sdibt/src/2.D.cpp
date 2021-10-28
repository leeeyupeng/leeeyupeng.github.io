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
    int n,k;
    int dp[MAXN][MAXN>>1];
public:
    void cacl()
    {
        for(int i = 0; i < MAXN; i ++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < MAXN; i ++){
            for(int j = 1;j <= min((i>>1),(MAXN>>1));j ++){
                dp[i][j] = dp[i-1][min(j,i-1-j)] + dp[i-1][min(j-1,i-1-(j-1))];
                dp[i][j]%=10000003;
            }
        }
    }
    void init(int n,int k){
        this->n = n;
        this->k = min(k,n-k);
    }
    int solve(){
        return dp[n][k];
    }
};
// int main(){
//     int testcases;
//     cin>>testcases;
//     Solution solution;
//     solution.cacl();
//     int n,k;
//     int value;
//     for(int i = 0; i<testcases; i ++){
//         cin>>n>>k;
//         solution.init(n,k);

//         auto ret = solution.solve();
//         cout<<ret<<endl;
//     }
//     return 0;
// }