#include"leetcode.h"

#define VMAX 100010
class DinnerPlates {
private:
    int capacity;
    vector<stack<int>*> vs;
    priority_queue<int,vector<int>,greater<int>> left;
    priority_queue<int,vector<int>,less<int>> right;
    int notuseindex;
public:
    DinnerPlates(int capacity):vs(VMAX) {
        this->capacity = capacity;
        notuseindex = 0;
    }
    
    void push(int val) {
        if(left.empty()){
            left.push(notuseindex);   
            vs[notuseindex] = new stack<int>();       
            notuseindex++;
        }
        int index = left.top();
        if(vs[index]->empty()){right.push(index);}
        vs[index]->push(val);
        if(vs[index]->size() == capacity){left.pop();}
    }
    
    int pop() {        
        while(!right.empty() && vs[right.top()]->empty()){
            right.pop();
        }
        if(right.empty()){return -1;}
        int index = right.top();
        if(vs[index]->size() == capacity){left.push(index);}
        int top = vs[index]->top();
        vs[index]->pop();
        if(vs[index]->empty()){right.pop();}
        return top;
    }
    
    int popAtStack(int index) {
        if(vs[index]==nullptr || vs[index]->empty()){return -1;}
        if(vs[index]->size() == capacity){left.push(index);}
        int top = vs[index]->top();
        vs[index]->pop();
        //if(vs[index].empty()){right.pop();}
        return top;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */