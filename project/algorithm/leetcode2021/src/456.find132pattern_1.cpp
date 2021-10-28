#include"leetcode.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){return false;}
        stack<pair<int,int>> s;
        s.push({nums[0],nums[0]});
        pair<int,int> top;
        for(int i = 1;i < n; i ++){
            top = s.top();
            while(!s.empty() && s.top().second <= nums[i]){
                s.pop();
            }
            while(!s.empty() && s.top().first == s.top().second){
                s.pop();
            }
            if(!s.empty() && s.top().first < nums[i]){
                return true;
            }

            if(top.first<nums[i]){
                s.push({top.first,nums[i]});
            }
            else{
                s.push({nums[i],nums[i]});
            }
        }
        return false;
    }
};

// int main(){
//     Solution solution;
//     vector<int> nums{1,4,0,-1,-2,-3,-1,-2};
//     auto ret = solution.find132pattern(nums);
//     return 0;
// }