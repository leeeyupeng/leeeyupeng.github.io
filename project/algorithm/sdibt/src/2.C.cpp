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
    bool isalphabetic(char c){
        return (c>='a' && c<= 'z') || (c>='A' && c<= 'Z');
    }
    bool isunderscore(char c){
        return c == '_';
    }
    bool isdigit(char c){
        return c>='0' && c<='9';
    }
public:
    bool solve(string str){
        int n = str.length();
        if(isalphabetic(str[0])|| isunderscore(str[0])){
            for(int i = 0; i < n; i ++){
                if(isalphabetic(str[i])|| isunderscore(str[i]) || isdigit(str[i])){

                }
                else{
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
};
// int main(){
//     int testcases;
//     cin>>testcases;
//     Solution solution;
//     string value;
//     getline (std::cin,value);
//     for(int i = 0; i<testcases; i ++){
//         //cin>>value;
//         getline (std::cin,value);
//         bool ret = solution.solve(value);
//         cout<<(ret?"Yes":"No")<<endl;
//     }
//     return 0;
// }