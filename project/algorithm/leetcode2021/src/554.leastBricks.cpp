#include"leetcode.h"


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> um;
        int n = wall.size();
        int i,j;
        int loc=0;

        for(i = 0; i < n;i ++){
            loc = wall[i][0];
            for(int j = 1;j < wall[i].size();j ++){
                if(um.find(loc)==um.end()){
                    um.insert({loc,0});
                }
                um[loc]++;
                loc += wall[i][j];
            }
        }

        int ret = n;
        for(unordered_map<int,int>::iterator ite  = um.begin();ite!=um.end();ite++){
            ret = min(ret,n - (*ite).second);
        }
        return ret;
    }
};