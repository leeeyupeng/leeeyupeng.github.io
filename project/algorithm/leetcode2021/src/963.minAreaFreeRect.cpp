#include"leetcode.h"

class Solution {
private:
    vector<int> ba{0,0};
    vector<int> bc{0,0};
    int dot;
    bool isRect(vector<int>& a,vector<int>& b,vector<int>& c,vector<int>& d,int& area){
        ba[0]=a[0]-b[0];ba[1]=a[1]-b[1];
        bc[0]=c[0]-b[0];bc[1]=c[1]-b[1];
        d[0] = c[0] + ba[0];
        d[1] = c[1] + ba[1];
        area = abs(ba[0] * bc[1] - ba[1] * bc[0]);
        dot = ba[0] * bc[0] + ba[1] * bc[1];
        return dot == 0;
    }
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_set<unsigned int> us;
        int n = points.size();
        for(int i = 0; i < n; i ++){
            us.insert((((unsigned int)points[i][0]) << 16) + (unsigned int)points[i][1]);
        }
        int ret = INT_MAX;
        int area=0;
        vector<int> d{0,0};
        for(int i = 0; i < n; i ++){
            for(int j = 0;j < n; j ++){
                for(int k = i+1; k < n; k ++){
                    if(i != j && i != k && j != k){
                        if(isRect(points[i],points[j],points[k],d,area)){
                            if(us.find((((unsigned int)d[0]) << 16) + (unsigned int)d[1])!=us.end()){
                                ret = min(ret,area);
                            }
                        }
                    }
                }
            }
        }
        if(ret == INT_MAX){return 0;}

        return ret;
    }
};

// int main(){
//     vector<vector<int>> points{
//         {1,2},{2,1},{1,0},{0,1}
//     };

//     Solution solution;
//     auto ret = solution.minAreaFreeRect(points);

//     return 0;
// }