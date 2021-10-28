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
#define MODULE 2012
#define MAXCHAR 26
class Solution{
private:
    int n;
    char letter[MAXN];
    int dp[MAXN];
    int f[MAXCHAR];
public:
    void init(int _n){
        n = _n;
    }
    void insert(int index,char c){
        letter[index] = c;
    }

    int solve(){
        char c;
        for(int i = 0; i < MAXCHAR; i ++){
            f[i] = 0;
        }
        for(int i = 0; i < n; i ++){
            c = letter[i]-'a';
            dp[i] = 0;
            for(int j = 0;j < c; j ++){
                dp[i] += f[j];
                dp[i] %= MODULE;
            }
            f[c] += dp[i] + 1;
        }

        for(int i = 0; i < MAXCHAR; i ++){
            f[i] = 0;
        }

        int dp2;
        int ret = 0;
        for(int i = n-1; i >= 0; i --){
            c = letter[i]-'a';
            dp2=0;
            for(int j = 0;j < c; j ++){
                dp2 += f[j];
                dp2 %= MODULE;
            }
            f[c] += dp2+1;

            ret += (dp[i] * dp2)% MODULE;
            ret%=MODULE;
        }
        return ret;
    }
};

// int main(){
//     int t;
//     //cin>>t;
//     Solution solution;
//     int n=0;
//     char c='a';
//     while(cin>>n){
//         //cin>>n;
//         solution.init(n);
//         for(int i= 0; i < n; i ++){
//             cin>>c;
//             solution.insert(i,c);
//         }

//         auto ret = solution.solve();
//         printf("%d\n",ret);
//     }
//     return 0;
// }