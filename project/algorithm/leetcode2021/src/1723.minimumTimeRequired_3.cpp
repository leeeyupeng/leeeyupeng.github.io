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
    bool dfs(vector<int>& jobs, int k,int value,int sumsvalue,vector<int> &p,int index,int curvalue){
        if(sumsvalue+curvalue > k * value){
            return false;
        }
        if(index == n){
            return true;
        }
        if(k==0){
            return false;
        }
        
        bool ret = false;
        int kk,ccurvalue;
        for(int i = index;i<n;i++){
            swap(p[index],p[i]);
            if(curvalue + jobs[p[index]]>value){
                kk = k-1;
                ccurvalue = jobs[p[index]];
            }
            else{
                kk = k;
                ccurvalue = curvalue + jobs[p[index]];
            }          
            ret|=dfs(jobs,kk,value,sumsvalue - jobs[p[index]],p,index+1,ccurvalue);
            //swap(p[index],p[i]);
            if(ret){return ret;}
        }
        return ret;
    }
    bool check(vector<int>& jobs, int k,int value,int sumsvalue){
        vector<int> p(n,0);
        for(int i = 0; i < n; i ++){p[i] = i;}

        return dfs(jobs,k,value,sumsvalue,p,0,0);
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
        return minvalue;
    }
};

// int main(){
//     Solution solution;
//     vector<int> jobs{254,256,256,254,251,256,254,253,255,251,251,255};
//     int k= 10;
//     auto ret = solution.minimumTimeRequired(jobs,k);
//     return 0;
// }