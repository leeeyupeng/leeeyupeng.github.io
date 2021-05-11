#include"leetcode.h"

class Solution {
private:
    int dfs(string& s,int index,vector<int> visit){
        if(index==-1){return 1;}
        if(visit[index]!=-1){return visit[index];}
        int ret = 0;
        if(s[index]!='0'){
            ret += dfs(s,index-1,visit);
        }

        if(index-1>=0){
            if(s[index-1] == '1' || (s[index-1] == '2' && s[index] <= '6')){
                ret += dfs(s,index-2,visit);
            }
        }
        visit[index] = ret;
        return ret;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> visit(n,-1);
        return dfs(s,n-1,visit);
    }
};