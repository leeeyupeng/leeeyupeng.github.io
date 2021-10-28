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


// int main(){
//     int n = 0;  
//     while(cin>>n && n > 0){
//         int value;
//         int minvalue=INT_MAX,maxvalue=0;
//         for(int i = 0; i < n; i ++){
//             cin>>value;
//             minvalue = min(minvalue,value);
//             maxvalue = max(maxvalue,value);
            
//         }
//         cout<<((maxvalue-minvalue)<<1)<<endl;
//     } 
//     return 0;
// }