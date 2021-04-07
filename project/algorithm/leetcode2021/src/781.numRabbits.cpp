#include"leetcode.h"

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int ret = 0;
        sort(answers.begin(),answers.end());
        int i = 0;
        int ii,jj,mid;
        while(i<n){
            ret += answers[i] + 1;
            ii = i;
            jj = min(i + answers[i] + 1,n);
            while(ii<jj){
                mid = (ii+jj)>>1;
                if(answers[mid] == answers[i]){
                    ii = mid+1;
                }
                else{
                    jj = mid;
                }
            }

            i = ii;
        }
        return ret;
    }
};