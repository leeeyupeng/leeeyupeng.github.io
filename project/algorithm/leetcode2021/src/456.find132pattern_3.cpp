#include"leetcode.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3){return false;}
        vector<int> leftmin(n,0);
        leftmin[0] = nums[0];
        for(int i = 1; i < n; i ++){
            leftmin[i] = min(leftmin[i-1],nums[i-1]);
        }
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n; i ++){
            while(!s.empty() && nums[s.top()] <= nums[i]){
                s.pop();
            }
            if(!s.empty() && leftmin[s.top()] < nums[i]){return true;}
            s.push(i);
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