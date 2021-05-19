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

#define MOD 997
class Solution{
private:
    int n;
    char p[MOD + 1];
    int getencode(char c){
        if(n==0){return 1;}
        int value = 1;
        int vv = 1;
        int nn = n;
        vv=c;
        while(nn!=0){
            value *= ((nn&0b1) == 0b1)?vv:1;
            value %= MOD;
            vv = vv * vv;
            vv%=MOD;
            nn>>=1;
        }
        return value;
    }
public:
    void init(int _n){
        n = _n;

        memset(p,0, sizeof(char) * (MOD + 1));

        int e;
        for(char c = 'a';c<= 'z';c++){
            e = getencode(c);
            if(p[e] != 0){
                p[e] = 1;
            }
            else{
                p[e] = c;
            }
        }

        for(char c = 'A';c<= 'Z';c++){
            e = getencode(c);
            if(p[e] != 0){
                p[e] = 1;
            }
            else{
                p[e] = c;
            }
        }

        for(char c = '0';c<= '9';c++){
            e = getencode(c);
            if(p[e] != 0){
                p[e] = 1;
            }
            else{
                p[e] = c;
            }
        }
        
    }

    void solve(string encode){
        int len = encode.length();
        if(len%3!=0){
            cout<<"No Solution"<<endl;
            return;
        }

        int cnum = len/3;
        int value;
        string ret;
        for(int i = 0; i < cnum; i ++){
            value = (encode[i*3] - '0')*100;
            value += (encode[i*3+1] - '0')*10;
            value += (encode[i*3+2] - '0');
            if(p[value]<=1){
                cout<<"No Solution"<<endl;
                return;
            }
            ret.push_back(p[value]);
        }
        cout<<ret<<endl;
    }
};
// int main(){
//     int c;
//     cin>>c;
//     Solution solution;
//     int n;
//     string encode;
//     int a,t,p;
//     for(int ic= 0; ic<c; ic ++){
//         cin>>n;
//         cin>>encode;
//         solution.init(n);
//         //printf("Case %d:\n",ic+1);
//         solution.solve(encode);   
//         cout<<endl;     
//     }
//     return 0;
// }