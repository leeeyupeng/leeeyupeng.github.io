#include"leetcode.h"

class Solution {
private:
    bool check(vector<int>& jobs, int k,int value){
        int n = jobs.size();
        vector<int> visit(n,0);
        vector<int> dp(value+1,-1);
        dp[0] = 0;
        int kk = k;
        while(kk>0){
            for(int j = 1;j<=value;j++){
                dp[j] = -1;
            }
            for(int i = 0; i < n; i ++){
                if(visit[i]==1){continue;}
                for(int j = value; j > 0;j--){
                    if(dp[j]==-1 &&j-jobs[i]>=0 && dp[j-jobs[i]]!=-1){
                        dp[j] = i;
                    }
                }
            }

            int j = value;
            while(j > 0){
                if(dp[j]!=-1){break;}
                j--;
            }
            if(j==0){break;}
            while(j!=0){
                visit[dp[j]] = 1;
                j = j - jobs[dp[j]];
            }
            kk --;
        }

        for(int i = 0; i < n; i ++){
            if(visit[i] == 0){
                return false;
            }
        }
        return true;
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        //sort(jobs.begin(),jobs.end(),less<int>());
        int minvalue,maxvalue;
        int sumsvalue = 0;
        for(int i = 0; i < n; i ++){
            sumsvalue += jobs[i];
        }
        maxvalue = sumsvalue;
        minvalue = ceil(1.0f * sumsvalue/k);
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
        return minvalue;
    }
};

// int main(){
//     Solution solution;
//     vector<int> jobs{1,2,4,7,8};
//     int k= 3;
//     auto ret = solution.minimumTimeRequired(jobs,k);
//     return 0;
// }