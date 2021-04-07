#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
//#include<functional>
//#include<parallel/algorithm>
using namespace std;

int main(){
    vector<int> v{1,20,3,40,5,6,7,80,9};
    for(int i = 0; i < 100000; i ++){
        v.push_back(rand() % 1000000);
    }
    
    sort(v.begin(),v.end());

    list<int> l{1,20,3,40,5,6,7,80,9};
    for(int i = 0; i < 100000; i ++){
        l.push_back(rand() % 1000000);
    }

    nth_element(v.begin(),v.begin() + 100,v.end());

    //l.sort();
    //sort(l.begin(),l.end());
    //sort();
    return 0;
}