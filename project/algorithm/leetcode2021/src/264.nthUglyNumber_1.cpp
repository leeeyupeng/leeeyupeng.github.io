#include"leetcode.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<double> pq;
        pq.push(1);
        int k = 1;
        double value;
        bool has = true;
        while(has){   
            has = false;         
            for(int i = k; i >=0; i --){
                for(int j = k-i; j >= 0; j --){
                    value = pow(2,i) * pow(3,j)*pow(5,k - i - j);
                    if(pq.size()<n){
                        has = true;
                        pq.push(value);
                    }
                    else if(pq.top() > value){
                        pq.pop();
                        has = true;
                        pq.push(value);
                    }
                }
            }
            k++;
        }
        return pq.top();
    }
};