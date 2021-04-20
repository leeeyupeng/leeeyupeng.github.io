#include"leetcode.h"
#include"leetcodenode.h"

class Solution {
private:
    struct node{
        int pointid;
        int cost;
        int hascnt;
    };
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int n = charge.size();
        int m = paths.size();
        vector<int> points(n,-1);
        vector<int> edges(m<<1,-1);
        for(int i = 0; i < m; i ++){
            edges[(i<<1)] = points[paths[i][0]];
            points[paths[i][0]] = (i<<1);

            edges[(i<<1) + 1] = points[paths[i][1]];
            points[paths[i][1]] = (i<<1) + 1;
        }

        auto cmp = [](node &a,node& b){
            if(a.cost == b.cost){
                if(a.hascnt == b.hascnt){
                    return a.pointid > b.pointid;                                    
                }
                return a.hascnt < b.hascnt;  
            }
            return a.cost > b.cost;
        };
        priority_queue<node,vector<node>,decltype(cmp)> pq(cmp);

        pq.push({start,0,0});
        int edgeid;
        int pathid;

        int nextpointid;
        unordered_set<int> us;
        while(!pq.empty()){
            node top = pq.top();
            if(top.pointid == end){
                return top.cost;
            }
            pq.pop();
            if(us.find((top.pointid<<8) + top.hascnt) != us.end()){continue;}
            us.insert((top.pointid<<8) + top.hascnt);
            edgeid = points[top.pointid];
            while(edgeid != -1){
                pathid = edgeid>>1;
                edgeid = edges[edgeid];

                if(paths[pathid][0] == top.pointid){
                    nextpointid = paths[pathid][1];
                }
                else{
                    nextpointid = paths[pathid][0];
                }

                for(int c = 0;c <= cnt - paths[pathid][2]; c++){
                    pq.push({nextpointid,top.cost + paths[pathid][2] + (paths[pathid][2] + c - top.hascnt) * charge[top.pointid],c});
                }
            }
        }

        return 0;
    }
};

// int main(){
//     vector<vector<int>> paths{
// {1,3,3},{3,2,1},{2,1,3},{0,1,4},{3,0,5}
//     };
//     int cnt=6;
//     int start=1; 
//     int end=0;
//     vector<int> charge{
// 2,10,4,1
//     };

//     Solution solution;
//     auto ret = solution.electricCarPlan(paths,cnt,start,end,charge);
//     return 0;
// }