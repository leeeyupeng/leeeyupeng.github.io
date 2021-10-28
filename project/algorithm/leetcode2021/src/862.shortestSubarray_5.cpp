#include"leetcode.h"

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> psums(n+1,0);
        psums[0] = 0;
        for(int i = 1; i <= n;i++){
            psums[i] = psums[i-1] + A[i-1];
        }
        int ret = n+1;
        deque<int> q;
        for(int i = 0; i <= n; i ++){
            while(!q.empty() && psums[q.back()] > psums[i]){
                q.pop_back();
            }
            q.push_back(i);
            while(!q.empty() && psums[q.back()] - psums[q.front()] >= K){
                ret  = min(ret,q.back() - q.front());
                q.pop_front();
            }
        }
        if(ret == n + 1){return -1;}
        return ret;
    }
};

// int main(){
//     Solution solution;

//     vector<int> A{84,-37,32,40,95};
//     auto ret = solution.shortestSubarray(A,167);

//     return 0;
// }