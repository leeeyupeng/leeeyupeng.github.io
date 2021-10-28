#include"leetcode.h"

#define RETMAX 2010
#define MAXNUM (1<<10)
class Solution {
private:
    int ret;
    int n;
    int k;
    void dfs(vector<int>& nums,int index,int value,int counter){
        if(counter>=ret){return;}
        if(index ==n){ret=min(ret,counter);}
        if(index<k){
            for(int b = 0; b<MAXNUM;b++){
                nums[index]^=b;
                value ^= nums[index];
                if(b!=0){counter++;}
                dfs(nums,index+1,value,counter);
                if(b!=0){counter--;}
                value ^= nums[index];
                nums[index]^=b;              
            }
        }
        else{
            if(value != 0){return;}
            value^=nums[index-k];
            value^=nums[index];
            nums[index]^=value;
            if(value!=0){counter++;}
            dfs(nums,index+1,0,counter);
            if(value!=0){counter++;}
            nums[index]^=value;
            value = 0;
        }
    }
public:
    int minChanges(vector<int>& nums, int k) {
        this->k = k;
        n = nums.size();
        ret = n;
        dfs(nums,0,0,0);
        return ret;
    }
};

// int main(){
//     Solution solution;

//     vector<int> nums={1,2,5,7,6,5,41,5,26,8,69,8,54,12,5,3,8,9,10,21,25,69,85,85,96,54,1,2,45,78,52,63,21,45,25,74,85,12,56,98,52,12,24,45,63,21,4,5,101,102,103,105,118,119,165,128,136};
//     int k= 5;
//     auto ret = solution.minChanges(nums,k);

//     return 0;
// }