#include"leetcode.h"


#define MAX 1000010
class MyHashSet {
private:
    vector<char> counter;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        counter = vector<char>(MAX,0);
    }
    
    void add(int key) {
        counter[key] = 1;
    }
    
    void remove(int key) {
        counter[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return counter[key] != 0;
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