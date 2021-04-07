#include"leetcode.h"

#define VMAX 100010
stack<int>* vs[VMAX];
class DinnerPlates {
private:
    int capacity;

    priority_queue<int,vector<int>,greater<int>> left;
    priority_queue<int,vector<int>,less<int>> right;
    int notuseindex;
    vector<stack<int>*> notuservs;
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
        notuseindex = 0;
    }
    
    void push(int val) {
        if(left.empty()){            
            left.push(notuseindex);  
            vs[notuseindex] = nullptr;
            notuseindex++;
        }
        int index = left.top();
        if(vs[index] == nullptr){
            if(notuservs.empty()){  
                vs[index] = new stack<int>();
            }
            else{
                vs[index] = notuservs.back();
                notuservs.pop_back();
            }
            right.push(index);
        }
        vs[index]->push(val);
        if(vs[index]->size() == capacity){left.pop();}
    }
    
    int pop() {     
        while(!right.empty() && (vs[right.top()]->empty())){
            notuservs.push_back(vs[right.top()]);
            vs[right.top()] = nullptr;
            right.pop();
        }
        if(right.empty()){return -1;}
        int index = right.top();
        if(vs[index]->size() == capacity){left.push(index);}
        int top = vs[index]->top();
        vs[index]->pop();
        if(vs[index]->empty()){
            notuservs.push_back(vs[index]);
            vs[index] = nullptr;
            right.pop();
        } 
        return top;
    }
    
    int popAtStack(int index) {
        if(index >= notuseindex){return -1;}
        if(vs[index]==nullptr || vs[index]->empty()){return -1;}
        if(vs[index]->size() == capacity){left.push(index);}
        int top = vs[index]->top();
        vs[index]->pop();
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


// int main(){
//     int capacity = 5;
//     DinnerPlates* obj = new DinnerPlates(capacity);
//     int type;
//     int value;
//     int index;
//     int ret;
//     for(int i = 0; i < 200000;i ++){
//         type = rand() % 3;
//         switch (type)
//         {
//         case 0:
//             value = rand() % 20000;
//             obj->push(value);
//             break;
//         case 1:
//             ret = obj->pop();
//             break;
//         case 2:
//             index =rand() % 100000;
//             ret = obj->popAtStack(index);
//             break;

//         }
//     }

//     return 0;
// }