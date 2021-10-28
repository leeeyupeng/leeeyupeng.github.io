#include"leetcode.h"

#define MAXN 1010
#define MAXCVALUE ((2<<16) + 10)
class Solution {
private:
    int n;
    char mem[2][MAXCVALUE];
    bool minmax(vector<int>& nums,int sums,char even,int index){
        if(sums == 0x0){return true;}
        if(mem[even][sums]!=0){return mem[even][sums] == 0x1;}
        bool ret = false;
        for(int i = index; i < n;i++){            
            swap(nums[index],nums[i]);
            ret|=!minmax(nums,sums^nums[index],even^0b1,index+1);
            swap(nums[index],nums[i]);
            if(ret==true){break;}            
        }
        mem[even][sums] = ret?0x1:0x2;
        return ret;        
    }
public:
    bool xorGame(vector<int>& nums) {
        n = nums.size();
        int sums = 0;
        for(int i = 0;  i < n; i ++){
            sums ^= nums[i];
        }
        memset(mem,0,sizeof(char) * 2 * MAXCVALUE);
        bool ret = minmax(nums,sums,0,0);
        return ret;
    }
};