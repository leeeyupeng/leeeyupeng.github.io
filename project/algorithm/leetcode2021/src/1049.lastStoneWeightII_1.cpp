#include"leetcode.h"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int MAXSUM = 0;
        for(int i = 0; i < n; i ++){
            MAXSUM+=stones[i];
        }
        set<int> sdp[2];
        set<int>::iterator ite;
        sdp[0].insert(0);
        for(int i = 0; i < n; i ++){
            for(ite = sdp[i&1].begin();ite!=sdp[i&1].end();ite++){
                if((*ite)+stones[i]<=MAXSUM){
                    if(sdp[(i+1)&1].find((*ite)+stones[i]) == sdp[(i+1)&1].end()){
                        sdp[(i+1)&1].insert((*ite)+stones[i]);
                    }
                }
                if((*ite)-stones[i]>=-MAXSUM){
                    if(sdp[(i+1)&1].find((*ite)-stones[i]) == sdp[(i+1)&1].end()){
                        sdp[(i+1)&1].insert((*ite)-stones[i]);
                    }
                }
            }
            sdp[i&1].clear();
        }
        ite = sdp[n&1].lower_bound(0);
        return *ite;
    }
};

// int main(){
//     vector<int> stones={2,7,4,1,8,1};
//     Solution solution;
//     auto ret = solution.lastStoneWeightII(stones);

//     return 0;
// }