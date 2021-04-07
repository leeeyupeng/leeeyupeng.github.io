#include"leetcode.h"

class Solution {
private:
    int toint(string& token){
        bool isnegative = false;
        int n = token.length();
        int i = 0;
        if(token[0] == '-'){isnegative=true;i++;}
        else if(token[0] == '+'){isnegative=false;i++;}
        int ret = 0;
        while(i<n){
            ret*=10;
            ret+=token[i]-'0';
            i++;
        }
        return isnegative==true?-ret:ret;
    }
    void oper(stack<int>& sdigit,char op){
        int a,b;
        b = sdigit.top();
        sdigit.pop();
        a = sdigit.top();
        sdigit.pop();
        int c;
        switch (op)
        {
        case '+':
            c = a+b;
            break;
        case '-':
            c = a-b;
            break;
        case '*':
            c = a*b;
            break;
        case '/':
            c = a/b;
            break;
        
        default:
            break;
        }
        sdigit.push(c);
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sdigit;
        int n = tokens.size();

        for(int i = 0; i < n; i ++){
            if(tokens[i].length()>1){
                sdigit.push(toint(tokens[i]));
            }
            else if(tokens[i][0] >= '0' && tokens[i][0]<='9'){
                sdigit.push(toint(tokens[i]));
            }
            else{
                oper(sdigit,tokens[i][0]);
            }
        }
        return sdigit.top();
    }
};