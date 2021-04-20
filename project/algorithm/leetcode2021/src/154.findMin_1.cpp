#include"leetcode.h"

class Solution {
private:
    int _findMin(vector<int>& nums,int n,int s,int e){
        int ret;
        int i,j,mid;
        i = s,j = e;        
        while(i<j){
            mid = (i+j)>>1;
            if(nums[mid] > nums[s]){
                i = mid+1;
            }
            else if(nums[mid] < nums[s]){
                j = mid;
            }
            else{
                if(i == s && j == e){
                    ret = _findMin(nums,n,i,mid);
                    if(ret < nums[s]){return ret;}
                    if(mid+1 != n){ret = min(ret,_findMin(nums,n,mid+1,j));}   
                    return ret;
                }
                else if(i==s){
                    i = mid+1;
                }
                else if(j == e){
                   j = mid;
                }
                else{
                    ret = _findMin(nums,n,i,mid);
                    if(ret < nums[s]){return ret;}
                    if(mid+1 != n){ret = min(ret,_findMin(nums,n,mid+1,j));}   
                    return ret;                    
                }
            }
        }

        
        if(i == n){return nums[s];}
        if(i == e){return min(nums[s],nums[e]);}
        
        return nums[i];
    }
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return _findMin(nums,n,0,n);
    }
};

// int main(){
//     vector<int> nums{2,2,2,2,1,2,2,2,2,2,2,2,2};
//     Solution solution;
//     auto ret = solution.findMin(nums);
//     return 0;
// }