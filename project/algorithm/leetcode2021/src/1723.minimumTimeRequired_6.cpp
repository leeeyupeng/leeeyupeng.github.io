#include"leetcode.h"

class Solution {
private:    
    int n;
    int k;
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
    pair<int,int> dfs(vector<int>& jobs, int k,int value,int p,vector<pair<int,int>> &vmem){
        if(vmem[p].first!=-2){return vmem[p];}
        pair<int,int> ret ={-1,0};
        int pp;
        int kk;
        int vvvalue;
        pair<int,int> ppair;
        for(int i = 0; i < n; i ++){            
            if(((p>>i)&0x1) == 0x1){
                pp = p & (~(1<<i));
                ppair = dfs(jobs,k,value,pp,vmem);
                if(ppair.first == -1){continue;}
                if(ppair.first>=k){continue;}
                if(ppair.second+jobs[i] > value){
                    kk = ppair.first + 1;
                    vvvalue=jobs[i];
                }
                else{
                    kk = ppair.first;
                    vvvalue=ppair.second+jobs[i];
                }
                if(kk>=k){continue;}
                if(ret.first == -1){
                    ret = {kk,vvvalue};
                }
                else if(ret.first > kk){
                    ret = {kk,vvvalue};
                }
                else if(ret.first == kk && ret.second > vvvalue){
                    ret = {kk,vvvalue};
                }
            }
        }
        vmem[p] = ret;
        return ret;
    }
    bool check(vector<int>& jobs, int k,int value){
        vector<pair<int,int>> vmem((1<<n),{-2,0});
        vmem[0] = {0,0};
        pair<int,int> ret = dfs(jobs,k,value,(1<<n) - 1,vmem);

        if(ret.first!=-1 && ret.first < k){return true;}
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