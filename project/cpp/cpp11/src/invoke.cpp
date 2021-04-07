#include<iostream>
#include<functional>
using namespace std;

typedef void funcprint(int a,char b,float c);
void print(int a,char b,float c){
    cout<<a <<"-"<<b<<"-"<<c<<endl;
}

template<typename... _Args>
void tprint(_Args... __args){
    print(__args...);
}

template<typename... _Args>
void ttprint(_Args&&... __args){
    print(std::forward<_Args>(__args)...);
}

template<typename func,typename... _Args>
void tttprint(func f,_Args... __args)
{
    (f)(__args...);
}

template<typename func,typename... _Args>
void ttttprint(func f,_Args&&... __args){
    (f)(std::forward<_Args>(__args)...);
}
// int main(){
//     std::invoke(print,10,'8',10.0f);
//     tprint(10,'8',10.0f);

//     funcprint *fp = print;
//     (fp)(10,'8',10.0f);

//     tttprint(print,10,'8',10.0f);
//     ttttprint(print,10,'8',10.0f);
//     return 0;
// }