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


class Solution{
private:
    char kv[256];
public:
    Solution(){
        kv[' '] = ' ';
        kv['n'] = 'u';
        kv['5'] = 's';
        kv['!'] = 'i';
        kv['w'] = 'm';
        kv['p'] = 'd';
        kv['u'] = 'n';
        kv['e'] = 'a';
        kv['a'] = 'e';
        kv['^'] = 'v';
        kv['o'] = 'o';
        kv['7'] = 'l';

    }
public:
    string solve(string &message){
        string ret;
        int n = message.length();
        for(int i = 0; i < n; i ++){
            ret.push_back(kv[message[i]]);
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// int main(){
//     int t;
//     cin>>t;
//     Solution solution;
//     string message;
//     pair<int,int> kind;
//     getline(cin,message);
//     for(int it = 0; it<t; it ++){
//         getline(cin,message);

//         auto ret = solution.solve(message);
//         printf("Case %d: ",it+1);
//         cout<<ret<<endl;
//     }
//     return 0;
// }