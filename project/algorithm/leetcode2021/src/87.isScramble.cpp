#include"leetcode.h"

class Solution {
private:
    unordered_map<int,char> us;
    bool dfs(string &s1, string &s2,int indexs1,int indexe1,int indexs2,int indexe2){
        int key = indexs1 * 30 * 30 + indexe1 * 30 + indexs2; 
        if(us.find(key)!=us.end()){return us[key];}
        bool ret = true;
        for(int i = 0; i <= indexe1-indexs1; i ++){
            if(s1[indexs1 + i] == s2[indexs2 + i]){}
            else{
                ret = false;
                break;
            }
        }
        if(ret == true){
            us[key] =ret;
            return ret;
        }
        int counter1[26];
        int counter2[26];
        int counter3[26];
        for(int i = 0; i < 26; i ++){
            counter1[i] = 0;
            counter2[i] = 0;
            counter3[i] = 0;
        }
        bool hascounter = false;
        for(int i = 0; i < indexe1-indexs1; i ++){
            counter1[s1[indexs1 + i]-'a'] ++;
            counter2[s2[indexs2 + i]-'a'] ++;
            counter3[s2[indexe2 - i]-'a'] ++;

            hascounter = true;
            for(int c = 0; c < 26;c ++){
                if(counter1[c] == counter2[c]){

                }
                else{
                    hascounter = false;
                    break;
                }
            }
            if(hascounter){
                ret |= (dfs(s1,s2,indexs1,indexs1 + i,indexs2,indexs2 + i)  && dfs(s1,s2,indexs1 + i + 1,indexe1,indexs2 + i + 1,indexe2));
                if(ret == true){break;}
            }

            hascounter = true;
            for(int c = 0; c < 26;c ++){
                if(counter1[c] == counter3[c]){

                }
                else{
                    hascounter = false;
                    break;
                }
            }

            if(hascounter){
                ret |= (dfs(s1,s2,indexs1,indexs1 + i,indexe2 - i,indexe2)  && dfs(s1,s2,indexs1 + i + 1,indexe1,indexs2,indexs2 + (indexe1 - (indexs1 + i + 1))));
                if(ret == true){break;}
            }
        }
        us[key] =ret;
        return ret;
    }
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        return dfs(s1,s2,0,n - 1,0,n-1);
    }
};

// int main(){
//     string s1 ="abb";
//     string s2 = "bba";
//     Solution solution;
//     auto ret = solution.isScramble(s1,s2);

//     return 0;
// }