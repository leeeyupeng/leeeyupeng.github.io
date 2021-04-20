#include"leetcode.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        int n = nums.size();
        int i = 0, j = 0;
        while(j<n){
            if(j - i < k){
                s.insert(nums[j]);
                j++;
            }
            else{
                s.insert(nums[j]);
                j++;
                s.erase(nums[i]);
                i++;                
            }
            if(j<n){
                set<int>::iterator ite = s.lower_bound(nums[j]);
                if(ite!=s.end()){
                    if((long long)(*ite) - (long long)nums[j]<=(long long)t){return true;}
                }
                if(ite!=s.begin()){
                    ite--;
                    if((long long)nums[j] - (long long)(*ite) <= (long long)t){return true;}
                }
            }
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