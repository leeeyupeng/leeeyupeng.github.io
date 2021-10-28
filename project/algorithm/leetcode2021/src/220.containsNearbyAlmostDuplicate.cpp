#include"leetcode.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        priority_queue<int,vector<int>,greater<int>> minpq;
        priority_queue<int,vector<int>,greater<int>> minpqremove;
        priority_queue<int,vector<int>,less<int>> maxpq;
        priority_queue<int,vector<int>,less<int>> maxpqremove;
        int n = nums.size();
        int i = 0, j = 0;
        while(j<n){
            if(j - i <= k){
                minpq.push(nums[j]);
                maxpq.push(nums[j]);
                j++;
            }
            else{
                if(maxpq.top() - minpq.top() <= t){
                    return true;
                }

                minpq.push(nums[j]);
                maxpq.push(nums[j]);
                j++;
                minpqremove.push(nums[i]);
                maxpqremove.push(nums[i]);
                i++;

                while(!minpqremove.empty()&&minpq.top() == minpqremove.top()){
                    minpq.pop();
                    minpqremove.pop();
                }
                while(!maxpqremove.empty()&&maxpq.top() == maxpqremove.top()){
                    maxpq.pop();
                    maxpqremove.pop();
                }
                
            }
        }

        if(maxpq.top() - minpq.top() <= t){
            return true;
        }

        return false;
    }
};

// int main(){
//     Solution solution;
//     vector<int> nums{1,2,3,1};
//     int k = 3;
//     int t = 0;

//     auto ret = solution.containsNearbyAlmostDuplicate(nums,k,t);

//     return 0;
// }