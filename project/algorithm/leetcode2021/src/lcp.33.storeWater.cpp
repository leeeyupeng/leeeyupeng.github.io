#include"leetcode.h"

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        auto cmp = [](pair<int,int> &a,pair<int,int>& b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        int ret1 = 0;
        for(int i = 0; i < n; i ++){
            if(bucket[i] == 0 && vat[i] != 0){
                bucket[i] ++;
                ret1 ++; 
            }
            if(vat[i] != 0){
                pq.push({i,(vat[i]/bucket[i]) + (vat[i]%bucket[i]==0?0:1)});
            }
        }
        if(pq.empty()){return 0;}
        int ret = ret1 + pq.top().second;
        int i;
        int ret2;
        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();
            i = top.first;
            ret = min(ret,ret1 + top.second);
            ret1++;
            bucket[i] ++;
            ret2 = (vat[i]/bucket[i]) + (vat[i]%bucket[i]==0?0:1);
            if(ret1 + ret2 > ret){
                break;
            }
            pq.push({i,ret2});
        }
        return ret;
    }
};

// int main(){
//     vector<int> bucket{
//         10
//     };
//     vector<int> vat{
//         10
//     };

//     Solution solution;
//     auto ret = solution.storeWater(bucket,vat);
//     return 0;
// }