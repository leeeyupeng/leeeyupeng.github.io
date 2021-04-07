#include"leetcode.h"

#define MAX 1000000007
class Fancy {
private:
    int n;
    vector<unsigned long long> vvalues;
public:
    Fancy() {
        n = 0;
        vvalues.clear();
    }
    
    void append(int val) {
        n++;
        vvalues.push_back(val);
    }
    
    void addAll(int inc) {
        for(int i = 0; i < n;i ++){
            vvalues[i] += inc;
            if(vvalues[i] >= (long long)MAX){vvalues[i] -= MAX;}
        }
    }
    
    void multAll(int m) {
        for(int i = 0; i < n;i ++){
            vvalues[i] *= m;
            if(vvalues[i] >= (long long)MAX){vvalues[i] %= MAX;}
        }
    }
    
    int getIndex(int idx) {
        if(idx>=n){return -1;}
        return vvalues[idx];
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */