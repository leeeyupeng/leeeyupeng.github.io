#include"leetcode.h"

class Solution {
    unordered_map<int,int> um;
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> counter(n+1,0);
        for(auto edge:edges){
            counter[edge[0]]++;
            counter[edge[1]]++;
        }
        int nq = queries.size();
        vector<int> ret(nq,0);
        int q;
        for(int i = 0 ; i< nq; i ++){
            q = queries[i];
            for(int j = 1; j <= n; j ++){
                if(counter[j]>q){
                    ret[i] += j-1;
                }
            }
        }
        return ret;
    }
};