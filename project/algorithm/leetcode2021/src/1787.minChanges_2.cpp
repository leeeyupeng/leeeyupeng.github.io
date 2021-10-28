#include"leetcode.h"

#define RETMAX 2010
#define MAXNUM (1<<10)
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n-k+1;
        vector<int> numsxor(m,0);
        int valuek=0;
        for(int i = 0; i < k; i ++){
            valuek ^= nums[i];
        }
        int ret = RETMAX;
        vector<int> numstemp(n,0);
        
        int value;
        int counter = 0;
        if(valuek == 0){
            value = valuek;
            counter = 0;
            for(int i = 0; i < n; i ++){
                numstemp[i] = nums[i];
            }
            for(int i = k; i < n; i ++){
                value ^= numstemp[i-k];
                value ^= numstemp[i];
                if(value !=0){
                    counter++;
                    numstemp[i]^=value;
                    value = 0;
                }
            }
            ret = min(ret,counter);
        }
        else{
            for(int j = 0;j<k;j ++){
                for(int i = 0; i < n; i ++){
                    numstemp[i] = nums[i];
                }
                value = valuek;
                counter = 0;
                numstemp[j]^= value;
                value = 0;
                counter++;
                for(int i = k; i < n; i ++){
                    value ^= numstemp[i-k];
                    value ^= numstemp[i];
                    if(value !=0){
                        counter++;
                        numstemp[i]^=value;
                        value = 0;
                    }
                }
                ret = min(ret,counter);
            }
        }

        return ret;
    }
};

// int main(){
//     Solution solution;

//     vector<int> nums={3,4,5,2,1,7,3,4,7};
//     int k= 3;
//     auto ret = solution.minChanges(nums,k);

//     return 0;
// }