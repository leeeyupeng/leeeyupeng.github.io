#include"leetcode.h"

#define POINTMAX 40010
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ret = INT_MAX;
        int n = points.size();
        int rect;
        bool i0j1,i1j0;
        unordered_set<int> us;
        for(int i = 0; i < n; i ++){
            us.insert(points[i][0] * POINTMAX + points[i][1]);
        }
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                if(points[i][0]!=points[j][0] && points[i][1] != points[j][1]){
                    i0j1 = us.find(points[i][0] * POINTMAX + points[j][1])!=us.end();
                    i1j0 = us.find(points[j][0] * POINTMAX + points[i][1])!=us.end();
                    if(i0j1 && i1j0){
                        rect = abs(points[i][0]-points[j][0]) * abs(points[i][1] - points[j][1]);
                        ret = min(ret,rect);
                    }
                }
            }
        }
        if(ret == INT_MAX){return 0;}
        return ret;
    }
};