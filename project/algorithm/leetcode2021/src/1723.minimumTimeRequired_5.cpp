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
    bool check(vector<int>& jobs, int k,int value,int sumsvalue){
        vector<pair<int,int>> dp(1<<n,{0,0});
        dp[0] = {k,0};
        int jj;
        int kk,vvalue;
        
        for(int j = 1;j < (1<<n);j++){
            for(int i = 0; i < n; i ++){
                if((j>>i) & 0x1 == 0x1)
                {
                    jj = j & (~(1<<i));
                    kk = dp[jj].first;
                    vvalue = dp[jj].second;
                    if(kk<=0){continue;}
                    else if(vvalue+jobs[i]>value){
                        kk--;
                        vvalue=jobs[i];
                    }else{
                        vvalue += jobs[i];
                    }
                    if(dp[j].first < kk){
                        dp[j] = {kk,vvalue};
                    }
                    else if(dp[j].first == kk && dp[j].second > vvalue){
                        dp[j] = {kk,vvalue};
                    }
                }
            }
        }
        kk = dp[(1<<n)-1].first;
        vvalue = dp[(1<<n)-1].second;
        if(kk > 0){return true;}
        return false;        
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
            if(check(jobs,k,mid,sumsvalue)){
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
//     vector<int> jobs{3,4,5,6,7,8,9,6,14,11,12,13};
//     int k= 5;
//     auto ret = solution.minimumTimeRequired(jobs,k);
//     return 0;
// }