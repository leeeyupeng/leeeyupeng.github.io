#include"leetcode.h"

class Solution {
private:
    enum Condition{
        condition_addsub,//=-
        condition_digit,//数字        
        condition_e,//e E
        condition_point,//小数点
        condition_end,//结束
        condition_error,//非法
        condition_count,
    };
    enum State{
        state_start,
        state_addsub,
        state_nodigitpoint,
        state_digit,
        state_point,
        state_pointdigit,
        state_e,
        state_eaddsub,
        state_edigit,
        state_success,
        state_fail,

        state_count,
    };

    State transition[State::state_count][Condition::condition_count]={
        {State::state_addsub,State::state_digit,State::state_fail,State::state_nodigitpoint,State::state_fail,State::state_fail},//state_start
        {State::state_fail,State::state_digit,State::state_fail,State::state_nodigitpoint,State::state_fail,State::state_fail},//state_addsub
        {State::state_fail,State::state_pointdigit,State::state_fail,State::state_fail,State::state_fail,State::state_fail},//state_nodigitpoint
        {State::state_fail,State::state_digit,State::state_e,State::state_point,State::state_success,State::state_fail},//state_digit
        {State::state_fail,State::state_pointdigit,State::state_e,State::state_fail,State::state_success,State::state_fail},//state_point
        {State::state_fail,State::state_pointdigit,State::state_e,State::state_fail,State::state_success,State::state_fail},//state_pointdigit
        {State::state_eaddsub,State::state_edigit,State::state_fail,State::state_fail,State::state_fail,State::state_fail},//state_e        
        {State::state_fail,State::state_edigit,State::state_fail,State::state_fail,State::state_fail,State::state_fail},//state_eaddsub
        {State::state_fail,State::state_edigit,State::state_fail,State::state_fail,State::state_success,State::state_fail},//state_edigit
        {State::state_fail,State::state_fail,State::state_fail,State::state_fail,State::state_success,State::state_fail},//state_success
        {State::state_fail,State::state_fail,State::state_fail,State::state_fail,State::state_fail,State::state_fail},//state_fail
    };
    Condition convert(char c){
        Condition condition=Condition::condition_error;
        if(c == '+' || c=='-'){condition =Condition::condition_addsub;}
        else if(c>='0'&&c<='9'){condition=Condition::condition_digit;}
        else if(c == 'e' || c=='E'){condition =Condition::condition_e;}
        else if(c == '.'){condition =Condition::condition_point;}
        return condition;
    }
public:
    bool isNumber(string s) {
        State state = State::state_start;
        Condition condition;
        int n = s.length();
        for(int i = 0; i < n; i ++){
            state = transition[state][convert(s[i])];
        }
        state = transition[state][Condition::condition_end];
        return state == State::state_success;
    }
};