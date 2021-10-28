#include"leetcode.h"

#define MAX 1000000007ll
class Fancy {
public:
    int vn;
    int on;
    vector<char> vvalues;
    vector<int> vindex;
    vector<char> vopertype;
    vector<pair<long long,int>> voper;
public:
    Fancy() {
        vn = 0;
        on = 0;
        vvalues.clear();
        voper.clear();
    }
    
    void append(int val) {
        vn++;
        vindex.push_back(on);
        vvalues.push_back(val);
    }
    
    void addAll(int inc) {
        vopertype.push_back(0);
        if(on == 0){            
            voper.push_back({1,inc});
        }
        else{
            voper.push_back({voper[on-1].first,(voper[on-1].second+inc) % MAX});
        }
        
        on++;

    }
    
    void multAll(int m) {
        vopertype.push_back(1);
        if(on == 0){            
            voper.push_back({m,0});
        }
        else{
            long long o1 = ((long long)voper[on-1].first * (long long)m) % MAX;
            o1 = max(o1,1ll);
            voper.push_back({o1,((long long)voper[on-1].second * (long long)m) % MAX});
        }
        on++;

    }
    
    int getIndex(int idx) {
        if(idx>=vn){return -1;}
        int index = vindex[idx];
        if(index == 0){
            return (((long long)vvalues[idx] * (long long)voper[on-1].first % MAX) + (long long)voper[on-1].second) % MAX;
        }
        else if(index == on){
            return vvalues[idx];
        }
        else{
            long long o1,o2;
            long long v1 = (long long)voper[on-1].first;
            long long v2 = (long long)voper[index-1].first;
            // while(v1%v2 != 0){
            //     v1 += MAX;
            // }
            o1 = (v1 / v2);
            o2 = ((long long)voper[on-1].second - (((long long)voper[index-1].second * o1) % MAX) + MAX) % MAX;
            return (((long long)vvalues[idx] * (long long)o1) + (long long)o2) % MAX;
        }
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


class Fancy2 {
public:
    int n;
    vector<unsigned long long> vvalues;
public:
    Fancy2() {
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

// int main(){
//     Fancy fancy;
//     Fancy2 fancy2;
//     int n = 100000;

//     int rrr = rand() % 100;
//     fancy.append(rrr);
//     fancy2.append(rrr);
//     for(int i = 0; i < n; i ++){
//         int r = rand()% 4;
//         int rr = rand()%100;
//         switch (r)
//         {
//         case 0:
//             fancy.append(rr);
//             fancy2.append(rr);
//             break;
//         case 1:
//             fancy.addAll(rr);
//             fancy2.addAll(rr);
//             break;
//         case 2:
//             fancy.multAll(rr);
//             fancy2.multAll(rr);
//             break;
//         case 3:
//             int idx = rand() % (fancy.vn + 10);
//             auto ret = fancy.getIndex(idx);
//             auto ret2 = fancy2.getIndex(idx);
//             if(ret != ret2){
//                 cout<<"error"<<endl;
//             }
//             break;
        
//         // default:
//         //     break;
//         }

//         for(int i = 0; i < fancy.vn;i ++){
//             auto ret = fancy.getIndex(i);
//             auto ret2 = fancy2.getIndex(i);
//             if(ret!=ret2){
//                 cout<<"error"<<endl;
//             }
//         }
//     }

//     return 0;
// }