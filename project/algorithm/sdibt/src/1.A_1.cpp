#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Solution{
private:
    bool cmp(string &a,string &b){
        int an = a.length(),bn = b.length();
        for(int i = 0; i < min(an,bn); i ++){
            if(a[i] != b[i]){return false;}
        }
        return true;
    }
public:
    bool hasprefix(vector<string> &pns){
        int n = pns.size();
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
                if(cmp(pns[i],pns[j])){return true;}
            }
        }
        return false;
    }
};

// int main(){
//     int n = 0;    
//     while(cin>>n && n > 0){
//         Solution solution;
//         bool ret=false;
//         vector<string>  pns(n);
//         for(int i = 0; i < n; i ++){
//             cin>>pns[i];
//         }
//         ret = solution.hasprefix(pns);
//         if(ret){printf("NO\n");}
//         else{printf("YES\n");}
//     }
//     return 0;
// }