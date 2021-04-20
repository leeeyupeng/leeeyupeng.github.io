#include"leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i=0,j=0;
        unordered_set<char> us;
        int ret = 0;
        while(j<n){
            if(us.find(s[j])!=us.end()){
                ret = max(ret,j-i);
                us.erase(s[i]);
                i++;
            }
            else{
                us.insert(s[j]);
                j++;
            }
        }
        ret = max(ret,j-i);
        return ret;
    }
};