#include"leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.length();
        int pn = p.length();
        vector<int> next(pn+1,-1);
        next[0] = -1;
        int i = 0,j = 0;
        int k = -1;
        int kk;
        while(i<sn){
            if(j == -1){break;}
            if(j == pn){
                j = next[j];
                k = next[j];
            }
            else if(j+1< pn && p[j+1] == '*'){
                next[j+1] = k;
                k = j + 1;
                j = j + 2;
                next[j] = k;
            }
            else if(s[i] == p[j]){
                if(k == -1){i++;j++;next[j] = k;}
                else if(p[k] == p[j]){k++;i++;j++;next[j] = k;}
                else if(p[k]=='.'){k++;i++;j++;next[j] = k;}
                else if(p[k]=='*' && p[k-1] == p[j]){
                    k++;i++;j++;
                    next[j] = k;
                }
                else{
                    k = next[k];
                }
            }
            else if(p[j] == '.'){
                if(k == -1){i++;j++;next[j] = k;}
                else if(p[k] == s[i]){k++;i++;j++;next[j] = k;}
                else if(p[k]=='.'){k++;i++;j++;next[j] = k;}
                else if(p[k]=='*' && p[k-1] == s[i]){
                    k++;i++;j++;next[j] = k;
                }
                else{
                    k = next[k];
                }
            }
            
            else if(p[j] == '*'){
                if(s[i] == p[j-1]){
                    if(k == -1){i++;j++; next[j] = k;}
                    else if(p[k] == p[j-1]){
                        k++;i++;j++;
                        k = next[j];
                    }
                    else if(p[k]=='.'){k++;i++;j++;next[j] = k;}
                    else if(p[k]=='*' && p[k-1] == p[j-1]){
                        k++;i++;j++;//next[j] = k;
                        next[j] = k;
                    }
                    else{
                        k = next[k];
                    }
                }
                else if(p[j-1] == '.'){
                    if(k == -1){i++;j++;next[j] = k;}
                    else if(p[k] == s[i]){k++;i++;j++;next[j] = k;}
                    else if(p[k]=='.'){k++;i++;j++;next[j] = k;}
                    else if(p[k]=='*' && p[k-1] == s[i]){
                        k++;i++;j++;next[j] = k;;
                    }
                    else{
                        k = next[k];
                    }
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