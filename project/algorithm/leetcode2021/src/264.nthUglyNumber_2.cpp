#include"leetcode.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> pq;        
        unordered_set<int> us;
        pq.push(1);
        long long value=0;
        long long top=0;
        int counter = 0;
        while(!pq.empty()){
            top = pq.top();
            pq.pop();
            if(us.find(top)!=us.end()){continue;}
            us.insert(top);
            counter ++;
            if(counter == n){return top;}            

            value = top << 1;
            if(value <= INT_MAX){pq.push(value);}
            value = top * 3;
            if(value <= INT_MAX){pq.push(value);}
            value = top * 5;
            if(value <= INT_MAX){pq.push(value);}
        }
        return 1;
    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.nthUglyNumber(1000);
//     return 0;
// }