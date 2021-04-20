#include"leetcode.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> next(m+1,0);
        next[0] = -1;
        int i=-1,j=0;
        while(j<m){
            if(i == -1){
                i++;j++;
                next[j] = i;
            }
            else if(needle[i] == needle[j]){
                i++;j++;
                next[j]=i;
            }
            else{
                i = next[i];
            }
        }
        i=0;j = 0;
        while(i<n){
            if(j==-1){
                i++;
                j++;
            }
            else if(haystack[i] == needle[j]){
                i++;j++;

                if(j == m){
                    return i - m;
                }
            }
            else{
                j = next[j];
            }
        }
        return -1;
    }
};