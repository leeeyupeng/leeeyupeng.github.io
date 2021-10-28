#include"leetcode.h"

class Solution {
private:    
    int n;
    int getmaxbound(vector<int>& jobs, int k){
        priority_queue <int,vector<int>,greater<int> > pq;
        for(int i = 0; i < k; i ++){
            pq.push(0);
        }
        int top;
        for(int i = 0; i < n; i ++){
            top = pq.top();
            pq.pop();
            pq.push(top+jobs[i]);
        }
        int ret = pq.top();
        while(!pq.empty()){
            ret = max(ret,pq.top());
            pq.pop();
        }
        return ret;
    }
    bool dfs(vector<int>& jobs, int k,int value,vector<int> &work,int index){
        if(index == n){return true;}
        int ret = false;
        for(int i = 0; i < k; i ++){
            if(i!=0){
                if(work[i] == 0 && work[i] == work[i-1]){
                    break;
                }
                else if(work[i] == work[i-1]){
                    continue;
                }
            }
            if(jobs[index] <= value - work[i]){
                work[i] += jobs[index];
                ret |= dfs(jobs,k,value,work,index+1);
                work[i] -= jobs[index];
                if(ret){return ret;}
            }
        }
        return ret;
    }
    bool check(vector<int>& jobs, int k,int value){
        vector<int> work(k,0);
        return dfs(jobs,k,value,work,0);
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        this->n = jobs.size();
        sort(jobs.begin(),jobs.end(),greater<int>());
        int minvalue = jobs[0],maxvalue;
        int sumsvalue = 0;
        for(int i = 0; i < n; i ++){
            sumsvalue += jobs[i];
            minvalue = max(minvalue,jobs[i]);
        }
        maxvalue = sumsvalue;
        minvalue = max(minvalue,(int)ceil(1.0f * sumsvalue/k));

        maxvalue = min(maxvalue,getmaxbound(jobs,k));
        
        int mid;
        while(minvalue<maxvalue){
            mid = (minvalue + maxvalue)>>1;
            if(check(jobs,k,mid)){
                maxvalue = mid;
            }
            else{
                minvalue = mid+1;
            }
        }
        return maxvalue;
    }
};

// int main(){
//     Solution solution;
//     vector<int> jobs{254,256,256,254,251,256,254,253,255,251,251,255};
//     int k= 10;
//     auto ret = solution.minimumTimeRequired(jobs,k);
//     return 0;
// }