#include"leetcode.h"

#define POINTMAX 40010
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ret = INT_MAX;
        int n = points.size();
        int rect;
        bool i0j1,i1j0;
        set<int> us;
        
        for(int i = 0; i < n; i ++){
            if(us.find(points[i][0]) == us.end()){us.insert(points[i][0]);}
            if(us.find(points[i][1]) == us.end()){us.insert(points[i][1]);}
        }
        int valuen = us.size();
        vector<int> value(valuen,0);
        vector<int> key(POINTMAX,-1);
        int i = 0;
        int j = 0;
        for(set<int>::iterator ite = us.begin();ite!=us.end(); ite++){
            value[i]=(*ite);            
            key[(*ite)] = i;
            i++;
        }
        vector<vector<char>> has(valuen,vector<char>(valuen,0));
        for(i = 0; i < n; i ++){
            has[key[points[i][0]]][key[points[i][1]]] = 1;
        }
        for(i = 0; i < n; i ++){
            for(j = i + 1; j < n; j ++){
                if(points[i][0]!=points[j][0] && points[i][1] != points[j][1]){
                    i0j1 = has[key[points[i][0]]][key[points[j][1]]] == 1;
                    i1j0 = has[key[points[j][0]]][key[points[i][1]]] == 1;
                    if(i0j1 && i1j0){
                        rect = abs(points[i][0]-points[j][0]) * abs(points[i][1] - points[j][1]);
                        ret = min(ret,rect);
                    }
                }
            }
        }
        if(ret == INT_MAX){return 0;}
        return ret;
    }
};