#include"leetcode.h"

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ret(n,0);

        vector<int> sorttasks(n,0);
        for(int i = 0; i < n; i ++){sorttasks[i] = i;}
        sort(sorttasks.begin(),sorttasks.end(),[& tasks](int a,int b){
            if(tasks[a][0] == tasks[b][0]){
                if(tasks[a][1] == tasks[b][1])
                {
                    return a<b;
                }
                return tasks[a][1] < tasks[b][1];
            }

            return tasks[a][0] < tasks[b][0];
        });

        auto cmp = [& tasks](int a,int b){
            if(tasks[a][1] == tasks[b][1]){
                return a>b;
            }
            return tasks[a][1] > tasks[b][1];
        };

        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        int counter = 0;
        int t = 0;
        int i = 0;
        int cur;
        while(counter<n){
            if(pq.empty()){
                pq.push(sorttasks[i]);                
                i ++;
            }
            else{
                cur = pq.top();
                pq.pop();
                t = max(t,tasks[cur][0]);
                while(i < n && t+tasks[cur][1]>=tasks[sorttasks[i]][0]){
                    pq.push(sorttasks[i]);
                    i ++;
                }

                {
                    t = t+tasks[cur][1];                    
                    ret[counter] = cur;
                    counter ++;
                }
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> tasks{
//         {19,13},{16,9},{21,10},{32,25},{37,4},{49,24},{2,15},{38,41},{37,34},{33,6},{45,4},{18,18},{46,39},{12,24}
//     };

//     auto ret = solution.getOrder(tasks);
//     return 0;
// }