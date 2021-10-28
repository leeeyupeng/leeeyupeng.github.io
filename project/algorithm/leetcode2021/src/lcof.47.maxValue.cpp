#include"leetcode.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        auto cmp = [](tuple<int,int,int>& a,tuple<int,int,int> &b){
            int ca = std::get<0>(a) + std::get<1>(a);
            int cb = std::get<0>(b) + std::get<1>(b);
            if(std::get<2>(a) / ca == std::get<2>(b) / cb){
                if(std::get<0>(a) == std::get<0>(b)){
                    return std::get<1>(a) > std::get<1>(b);
                }
                return std::get<0>(a) > std::get<0>(b);
            }
            return std::get<2>(a) / ca < std::get<2>(b) / cb;
        };
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,decltype(cmp)> pq(cmp);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,-1));
        pq.push({0,0,grid[0][0]});
        tuple<int,int,int> top;
        int ret = grid[0][0];
        while(!pq.empty()){
            top = pq.top();
            pq.pop();
            if(visit[std::get<0>(top)][std::get<1>(top)]>=std::get<2>(top)){continue;}
            visit[std::get<0>(top)][std::get<1>(top)]=std::get<2>(top);
            if(std::get<0>(top) < m - 1){
                pq.push({std::get<0>(top) + 1,std::get<1>(top),std::get<2>(top) + grid[std::get<0>(top) + 1][std::get<1>(top)]});
            }
            if(std::get<1>(top) < n - 1){
                pq.push({std::get<0>(top) ,std::get<1>(top)+ 1,std::get<2>(top) + grid[std::get<0>(top)][std::get<1>(top)+ 1]});
            }
            if(std::get<0>(top) == m -1 && std::get<1>(top) == n-1){
                ret = max(ret,std::get<2>(top));
            }
        }
        return ret;
    }
};

// int main(){
//     vector<vector<int>> grid{
//         {1,3,1},
//         {1,5,1},
//         {4,2,1}
//     };

//     Solution solution;
//     auto ret = solution.maxValue(grid);

//     return 0;
// }