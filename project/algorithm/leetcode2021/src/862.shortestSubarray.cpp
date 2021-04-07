#include"leetcode.h"

class Solution {
    bool _shortestSubarray(vector<int>& A,int nums, int K){
        int n = A.size();
        int i = 0,j = 0;
        long long sums=0;        
        for(int i = 0; i< nums; i ++){
            sums+=A[i];
        }
        while(sums>=K){
            return true;
        }
        for(int j = nums;j < n ;j ++){
            sums+=A[j];
            sums-=A[j-nums];

            while(sums>=K){
                return true;
            }
        }
        return false;
    }
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        long long sums = 0;
        for(int i = 0; i < n; i ++){
            sums+=A[i];
        }
        int i = 0,j = n;
        int mid;
        bool isexit;
        while(i<j){
            mid = (i+j)>>1;
            isexit = _shortestSubarray(A,(mid+1),K);
            if(isexit){j = mid;}
            else{i = mid+1;}
        }
        if(i>=n){return -1;}
        return i + 1;
    }
};

// int main(){
//     Solution solution;

//     vector<int> A{84,-37,32,40,95};
//     auto ret = solution.shortestSubarray(A,167);

//     return 0;
// }