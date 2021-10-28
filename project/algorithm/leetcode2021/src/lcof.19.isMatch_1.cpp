#include"leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.length();
        int pn = p.length();
        vector<int> next(pn+1,-1);
        for(int i = 0; i <= pn; i ++){next[i] = -1;}
        next[0] = -1;
        int k = -1;
        int i = 0,j = 0;
        while(i < sn){
            if(j == -1){break;}
            if(j==pn){
                j = next[j];  
                k = next[j];              
            }
            else if(j + 1 < pn && p[j+1] == '*'){
                j++;
                next[j] = k; 
                k = j;
                j++;
                next[j] = k;
            }
            else if(s[i] == p[j]){    
                while(k!=-1 &&k!= next[k] && p[k] != p[j]&& !(p[k] == '*' && p[k-1] == s[i])){k = next[k];}
                if(k!=-1){k++;}
                j++;
                next[j] = k;
                i++;
            }
            else if(p[j] == '.'){                
                while( k!=-1 && k!= next[k] && p[k] != s[i] && !(p[k] == '*' && p[k-1] == s[i])){k = next[k];}
                if(k!=-1){k++;}
                j++;
                next[j] = k;
                i++;
            }
            else if(p[j] == '*'){
                if(s[i] == p[j-1] || p[j-1] == '.'){
                    if(k!=-1){k++;}
                    i++;j++;
                }
                else{
                    j = next[j];
                    k = next[j]; 
                }
            }
            else{                            
                j = next[j];   
                k = next[j];            
            }
        }
        while(j<pn){
            if(j+1<pn && p[j+1]=='*'){
                j += 2;
            }
            else{break;}
        }
        return i == sn && j == pn;
    }
};

// int main(){
//     Solution solution;
//     string s = "aaba";
//     string p = "ab*a*c*a";
//     auto ret = solution.isMatch(s,p);
//     return 0;
// } 