#include"leetcode.h"


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};


class NestedIterator {
private:
    stack<NestedInteger*> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {        
        for(int i = nestedList.size()-1; i >=0; i --){
            s.push(&nestedList[i]);
        }
    }
    
    int next() {
        NestedInteger* temp;
        NestedInteger* top;        
        while(!s.empty() && !s.top()->isInteger()){
            top=s.top();
            s.pop();
            for(int i = top->getList().size()-1; i >=0; i --){
                temp = const_cast<NestedInteger*>(&(top->getList()[i]));
                s.push(temp);
            }
        }
        top = s.top();
        s.pop();
        return top->getInteger();
    }
    
    bool hasNext() {
        NestedInteger* temp;
        NestedInteger* top;        
        while(!s.empty() && !s.top()->isInteger()){
            top=s.top();
            s.pop();
            for(int i = top->getList().size()-1; i >=0; i --){
                temp = const_cast<NestedInteger*>(&(top->getList()[i]));
                s.push(temp);
            }
        }
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */