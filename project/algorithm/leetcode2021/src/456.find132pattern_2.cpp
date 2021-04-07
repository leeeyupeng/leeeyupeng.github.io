#include"leetcode.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3){return false;}
        //左边最小的
        vector<int> leftmin(n,0);
        leftmin[0] = nums[0];
        for(int i = 1; i < n; i ++){
            leftmin[i] = min(leftmin[i-1],nums[i-1]);
        }
        //右边小于i的最大值
        vector<int> rightmin(n,0);
        set<int> s;
        set<int>::iterator ite;
        for(int i = n-1; i >= 0; i --){
            s.insert(nums[i]);
            ite = s.lower_bound(nums[i]);
            if(ite!=s.begin()){
                ite--;
            }
            rightmin[i]=(*ite);
        }
        for(int i = 0; i < n; i ++){
            if(leftmin[i] < nums[i] && leftmin[i] < rightmin[i] && nums[i] > rightmin[i]){return true;}
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