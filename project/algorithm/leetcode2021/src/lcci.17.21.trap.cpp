#include"leetcode.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int lh=0,rh=0;
        int i= 0,j = height.size();
        int ret = 0;
        while(i<j){
            if(lh<=rh){
                ret += max(0,lh-height[i]);
                lh = max(lh,height[i]);
                i++;
            }
            else{
                j--;
                ret += max(0,rh-height[j]);
                rh = max(rh,height[j]);                
            }
        }
        return ret;
    }
};