#include"leetcode.h"

class Solution {
public:
    int clumsy(int N) {
        if(N==1){return N;}
        else if(N == 2){return N* (N-1);}
        else if(N==3){return N* (N-1) / (N-2);}
        else{
            int ret = N* (N-1) / (N-2);
            N -= 3;
            while(N>=4){
                ret += N - (N-1)* (N-2) / (N-3);
                N-=4;
            }
            if(N == 1){ret+=N;}
            else if(N==2){ret+= N - (N-1);}
            else if(N==3){ret+=N - (N-1) * (N-2);}
            return ret;
        }
    }
};