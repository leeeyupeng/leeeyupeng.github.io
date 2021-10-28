#include"leetcode.h"

class Solution {
private:
    void dfs(vector<int>& nums,vector<vector<int>>& ret,vector<int>& sub,int index,bool flag){
        if(index == nums.size()){
            ret.push_back(sub);
            return;
        }
        
        if(flag == false && nums[index] == nums[index-1]){}
        else{
            sub.push_back(nums[index]);
            dfs(nums,ret,sub,index+1,true);
            sub.pop_back();
        }
        dfs(nums,ret,sub,index+1,false);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> sub;
        sort(nums.begin(),nums.end());
        dfs(nums,ret,sub,0,true);
        return ret;
    }
};