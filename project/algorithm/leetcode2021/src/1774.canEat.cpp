#include"leetcode.h"

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        int qn = queries.size();
        vector<long long> sums(n,0);
        sums[0] = candiesCount[0];
        for(int i = 1; i < n; i ++){
            sums[i] = sums[i-1] + candiesCount[i];
        }

        vector<bool> answer(qn,false);
        long long favoriteType;
        long long favoriteDay;
        long long dailyCap;
        for(int i = 0; i < qn; i ++){
            favoriteType = queries[i][0];
            favoriteDay = queries[i][1]+1;
            dailyCap = queries[i][2];
            if(favoriteDay> sums[favoriteType]){
                answer[i] = false;
            }
            else if(favoriteType - 1 >= 0 && dailyCap * favoriteDay <= sums[favoriteType - 1]){
                answer[i] = false;
            }
            else{
                answer[i] = true;
            }
        }
        return answer;
    }
};