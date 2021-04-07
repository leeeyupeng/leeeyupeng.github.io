#include"leetcode.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){return false;}
        int premin = nums[0];
        for(int i = 1; i < n; i ++){
            if(nums[i] <= premin){
                premin = min(premin,nums[i]);
                continue;
            }
            for(int j = i + 1; j < n; j ++){
                if(premin < nums[j] && nums[j] < nums[i]){
                    return true;
                }
            }
            
        }
        return false;
    }
};