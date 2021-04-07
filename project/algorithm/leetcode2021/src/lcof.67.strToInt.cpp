#include"leetcode.h"

class Solution {
public:
    int strToInt(string str) {
        bool isnagative = false;
        long long ret = 0;
        int i = 0;
        int n = str.length();
        bool isstart = false;
        while(i<n){
            if(str[i]==' '){
                if(isstart == false){}
                else{break;}
            }
            else if(str[i]>='0' && str[i]<='9'){
                if(isstart == false){isstart = true;}
                ret *= 10;
                ret += str[i] - '0';
                ret = min(ret,(long long)INT_MAX + (long long)1);
            }
            else if(str[i] == '+'){
                if(isstart == false){isstart = true;isnagative=false;}
                else{break;}
            }
            else if(str[i] == '-'){
                if(isstart == false){isstart = true;isnagative=true;}
                else{break;}
            }
            else{
                break; 
            }

            i ++;
        }
        ret =  ret * (isnagative?-1:1);
        ret = min(ret,(long long)INT_MAX);
        ret = max(ret,(long long)INT_MIN);
        return ret;
    }
};

// int main()
// {
//     Solution solution;
//     auto ret = solution.strToInt("-91283472332");
//     return 0;
// }