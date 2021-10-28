#include"leetcode.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();        
        if(n<=2){return n;}
        int i=2,j=2;
        while(j<n){
            if(nums[i-2]==nums[i-1]){
                while(nums[i-1] == nums[j]){j++;}
            }
            {
                nums[i] = nums[j];
                i ++;j ++;
            }
        }
        return i;
    }
};