#include"leetcode.h"

#define RETMAX 2010
#define MAXNUM (1<<10)
class Solution {
private:
    int n,k;
    int getsize(int i){
        return n/k + (n%k>=(i+1)?1:0);
    }

    void getcount(vector<int>& nums,int i,unordered_map<int,int> &um){
        for(int ii = i; ii < n;){
            if(um.find(nums[ii])== um.end()){
                um.insert({nums[ii],0});                
            }
            um[nums[ii]]++;
            
            ii+=k;
        }
    }
public:
    int minChanges(vector<int>& nums, int k) {
        this->n = nums.size();
        this->k = k;
        vector<int> dp[2];

        unordered_map<int,int> um;
        int xcount;
        int isize;
        int x;
        int dpmin[2];
        dp[0] = vector<int>(MAXNUM,RETMAX);
        dp[1] = vector<int>(MAXNUM,RETMAX);
        dp[1][0] = 0;
        dpmin[1] = 0;
        unordered_map<int,int>::iterator ite;
        for(int i = 0; i < k; i ++){
            um.clear();
            getcount(nums,i,um);
            isize = getsize(i);
            dpmin[i&0b1] = RETMAX;
            for(int b = 0; b< MAXNUM;b++){
                dp[i&0b1][b] = RETMAX;
                for(ite = um.begin();ite!=um.end();ite++){
                    x = ite->first;
                    xcount = ite->second;
                    dp[i&0b1][b] = min(dp[i&0b1][b],dp[(i-1+2)&0b1][b^x]+isize-xcount);
                }
                dp[i&0b1][b] = min(dp[i&0b1][b],dpmin[(i-1 + 2)&0b1] + isize);

                dpmin[i&0b1] = min(dpmin[i&0b1],dp[i&0b1][b]);
            }
        }

        return dp[(k-1)&0b1][0];
    }
};

// int main(){
//     Solution solution;

//     vector<int> nums={1,2,0,3,0};
//     int k= 1;
//     auto ret = solution.minChanges(nums,k);

//     return 0;
// }