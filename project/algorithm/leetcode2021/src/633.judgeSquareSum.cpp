#include"leetcode.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0,j = sqrt(c);
        int value;
        while(i<=j){
            value = i*i+j*j;
            if(value < c){i++;}
            else if(value>c){j--;}
            else{
                return true;
            }
        }
        return false;
    }
};