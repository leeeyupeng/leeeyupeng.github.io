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
class Solution{
private:
    int n;
    char letter[MAXN];
    int dpleft[MAXN];
    int dpright[MAXN];
public:
    void init(int _n){
        n = _n;
    }
    void insert(int index,char c){
        letter[index] = c;
    }

    int solve(){        
        int flag[26];
        for(int i = 0; i < 26; i ++){
            flag[i] = INT_MIN;
        }
        for(int i = 0; i < n; i ++){
            dpleft[i] = 0;
            for(int j = 0; j < letter[i]-'a';j++){
                if(flag[j]!=INT_MIN && flag[j] > flag[letter[i]-'a']){
                    dpleft[i] += dpleft[flag[j]] + 1;
                }
            }
            // if(flag[letter[i]-'a']!=INT_MIN){
            //     dpleft[i] += dpleft[flag[letter[i]-'a']];
            // }
            flag[letter[i]-'a'] = i;
        }

        for(int i = 0; i < 26; i ++){
            flag[i] = INT_MAX;
        }

        for(int i = n-1; i >= 0; i --){
            dpright[i] = 0;
            for(int j = 0; j < letter[i]-'a';j++){
                if(flag[j]!=INT_MAX && flag[j] < flag[letter[i]-'a']){
                    dpright[i] += dpright[flag[j]] + 1;
                }
            }
            // if(flag[letter[i]-'a']!=INT_MAX){
            //     dpright[i] += dpright[flag[letter[i]-'a']];
            // }
            flag[letter[i]-'a'] = i;
        }
        int ret = 0;
        for(int i = 1; i < n-1; i ++){
            ret+=(dpleft[i]*dpright[i]) % MODULE;
        }
        return ret;
    }
};
// int main(){
//     int t;
//     //cin>>t;
//     Solution solution;
//     int n;
//     char c;
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