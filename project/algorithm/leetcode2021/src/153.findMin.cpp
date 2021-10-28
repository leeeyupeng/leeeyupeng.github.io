#include"leetcode.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = n;
        int mid;
        while(i<j){
            mid = (i+j)>>1;
            if(nums[mid]>=nums[0]){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        if(i==n){i = 0;}
        return nums[i];
    }
};