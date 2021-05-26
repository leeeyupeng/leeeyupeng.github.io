#include"leetcode.h"

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> sta;
        int n = s.length();
        string top;
        string value;
        for(int i = 0; i < n; i ++){
            if(s[i] == '('){
                sta.push(value);
                value.clear();
                sta.push("(");                
            }
            else if(s[i] == ')'){
                sta.pop();
                reverse(value.begin(),value.end());
                top = sta.top();
                sta.pop();
                value = top+value;
            }
            else{
                value.push_back(s[i]);
            }
        }
        return value;
    }
};

// int main()
// {
//     Solution solution;
//     auto ret = solution.reverseParentheses("(u(love)i)");
//     return 0;
// }