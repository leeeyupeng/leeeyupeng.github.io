#include"leetcode.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> strnums(n,"");
        int num = 0;
        for(int i = 0; i < n; i ++){
            num = nums[i];
            if(num == 0){strnums[i] = "0";continue;}
            while(num!=0){
                strnums[i].push_back(num%10 + '0');
                num /= 10;
            }
            reverse(strnums[i].begin(),strnums[i].end());
        }
        vector<int> sortnums(n,0);
        for(int i = 0; i < n; i ++){sortnums[i]=i;}
        sort(sortnums.begin(),sortnums.end(),[&strnums](int &a,int &b){
            int i = 0;
            string &stra = strnums[a]; 
            string &strb = strnums[b];
            int na = stra.length();
            int nb = strb.length();
            int nn = na*nb;
            while(i<nn){
                if(stra[i%na] == strb[i%nb]){i++;}
                else{return stra[i%na] > strb[i%nb];}
            }
            return a<b;
        });
        if(strnums[sortnums[0]] == "0"){return "0";}
        string ret="";
        for(int i = 0; i < n; i ++){
            ret.append(strnums[sortnums[i]]);
        }
        return ret;
    }
};