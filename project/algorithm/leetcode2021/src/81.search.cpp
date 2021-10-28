#include"leetcode.h"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int k = 0;
        int i,j ,mid;
        int n = nums.size();
        if(n==0){return false;}
        i = 0,j = n;
        while(j>0){
            if(nums[0] == nums[j-1]){j--;}
            else{break;}
        }
        while(i<j){
            mid = (i+j)>>1;
            if(nums[mid] >= nums[0]){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        k = i;        
        i = 0,j = k;
        while(i<j){
            mid = (i+j)>>1;
            if(nums[mid] < target){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        if(i!=k && nums[i]==target){
            return true;
        }

        i = k,j = n;
        while(i<j){
            mid = (i+j)>>1;
            if(nums[mid] < target){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        if(i!=n && nums[i]==target){
            return true;
        }
        return false;
    }
};