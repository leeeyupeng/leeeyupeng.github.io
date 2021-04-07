#include"leetcode.h"

class Solution {
    int _shortestSubarray(vector<int>& A,long long llk){
        int n = A.size();
        int ret = 0;
        int i = 0,j = 0;
        long long sums=0;        
        while(j<n){
            if(sums<llk){sums+=A[j];j++;}
            else{
                ret = max(ret,j-i);
                sums-=A[i];
                i ++;
            }
        }
        while(sums>=llk){
            ret = max(ret,j-i);
            sums-=A[i];
            i ++; 
        }
        return ret;
    }
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        for(int i = 0; i < n; i ++){
            A[i] += 100000ll;
        }

        long long sums = 0;
        for(int i = 0; i < n; i ++){
            sums+=A[i];
        }
        int i = 1,j = n+1;
        int mid;
        int nums;
        while(i<j){
            mid = (i+j)>>1;
            nums = _shortestSubarray(A,(long long)K + (long long)(mid) * 100000ll);
            if(sums >= (long long)K + (long long)(mid) * 100000ll && nums>=mid){j = mid;}
            else{i = mid+1;}
        }
        if(i>n){return -1;}
        return i;
    }
};

// int main(){
//     Solution solution;

//     vector<int> A{84,-37,32,40,95};
//     auto ret = solution.shortestSubarray(A,167);

//     return 0;
// }