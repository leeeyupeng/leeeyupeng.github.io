#include"leetcode.h"
#include<bitset>

#define MAX 1000010
class MyHashSet {
private:
    bitset<MAX> bit{0};
public:
    /** Initialize your data structure here. */
    MyHashSet() {
    }
    
    void add(int key) {
        bit[key] = 1;
    }
    
    void remove(int key) {
        bit[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return bit[key] != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// int main(){
//     MyHashSet hash;
//     hash.add(1);
//     hash.add(2);
//     hash.add(2);
//     hash.remove(2);
//     auto ret = hash.contains(2);

//     return 0;
// }