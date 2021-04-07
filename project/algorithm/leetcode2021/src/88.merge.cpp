#include"leetcode.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int ij = m+n-1;
        while(j>=0){
            if(i < 0){
                nums1[ij] = nums2[j];
                ij --;j --;
            }
            else if(nums1[i] > nums2[j]){
                nums1[ij] = nums1[i];
                i --;ij--;
            }
            else{
                nums1[ij] = nums2[j];
                ij --;j --;
            }
        }
    }
};