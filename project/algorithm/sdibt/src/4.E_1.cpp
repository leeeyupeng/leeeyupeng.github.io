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
#define MODULE 2012
class Solution{
private:
    int n;
    char letter[MAXN];
public:
    void init(int _n){
        n = _n;
    }
    void insert(int index,char c){
        letter[index] = c;
    }

    int solve(){  
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