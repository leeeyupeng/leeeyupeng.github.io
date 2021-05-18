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

#define MAXN 10010
class Solution{
private:
    int n;
    int arr[MAXN];
    int bit[30];
public:
    inline void init(int n){
        this->n = n;
        memset(bit,0,sizeof(int) * 30);
    }

    inline void add(int index,int value){
        arr[index] = value;
    }

    bool solve(){
        int value;
        int i,j;
        for(i = 0; i < n; i ++){
            value = arr[i];
            j = 0;
            while(value!=0){
                bit[j] += value&0b1;
                value>>=1;
                j++;
            }
        }
        for(i = 0; i < 30; i ++){
            if((bit[i] & 0b11) !=0){break;}
        }
        return i != 30;
    }
};

// int main(){
//     int testcases;
//     cin>>testcases;
//     Solution solution;
//     int n;
//     int value;
//     for(int i = 0; i<testcases; i ++){
//         cin>>n;
//         //n = 10000;
//         solution.init(n);
//         for(int j = 0; j < n; j ++){
//             cin>>value;
//             //value = rand() % 10000000;
//             solution.add(j,value);
//         }

//         auto ret = solution.solve();
//         cout<<(ret?"Yes":"No")<<endl;
//     }
//     return 0;
// }