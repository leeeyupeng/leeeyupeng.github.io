#include<iostream>
using namespace std;

template <typename T> 
struct my_is_void
{ 
    static const bool value = false; 
};

template <> 
struct my_is_void<void>
{ 
    static const bool value = true; 
};

template<typename T1,typename T2>
struct my_is_same{
    static const bool value = false;
};

template<typename T>
struct my_is_same<T,T>{
    static const bool value = true;
}; 

// int main(){
//     cout<<my_is_void<int>::value<<endl;
//     cout<<my_is_void<void>::value<<endl;
    
//     cout<<my_is_same<int, float>::value<<endl;
//     cout<<my_is_same<int, int>::value<<endl;

//     return 0;
// }