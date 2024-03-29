#include"leetcode.h"

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        int ret = 0;
        vector<int> sums(n,0);
        sums[0] = A[0];
        int nums;
        for(int i = 1; i < n; i ++){
            sums[i]=sums[i-1]+A[i];
        }
        for(int i = 0; i < n; i ++){
            for(int j = i; j < n && (ret == 0 || j <= i + ret); j ++){
                if(i == 0){
                    nums = sums[j];
                }
                else{
                    nums = sums[j] - sums[i-1];
                }
                if(nums>=K){
                    if(ret == 0){ret = j - i + 1;}
                    else{
                        ret = min(ret,j- i + 1);
                    }
                }
            }
        }
        if(ret == 0){return -1;}
        return ret;
    }
};

// int main(){
//     Solution solution;

//     vector<int> A{84,-37,32,40,95};
//     auto ret = solution.shortestSubarray(A,167);

//     return 0;
// }