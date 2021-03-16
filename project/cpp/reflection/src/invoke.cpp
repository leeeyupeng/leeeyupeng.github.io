#include<iostream>
#include<functional>
using namespace std;

class Object{
private:
    int objid;
public:
    void f1(){cout<<"Object f1()"<<endl;}
    int f2(int a){cout<<"Object f2()"<<endl;}
};

class A:Object{
public:
    int af1(int a,char b,float c){cout<<"A af1():"<<a<<"-"<<b<<"-"<<c<<endl;return 1;}
};

class B:Object{
public:
    void bf1(){cout<<"B bf1()"<<endl;}
};

typedef int (A::*func_t)(int a,char b,float c);

template<typename _Functor>
class Method{
private:
public:
    _Functor __fn;

    void print(){}

    template<typename _Object,typename... _Args>
    decltype((declval<_Object>().*declval<_Functor>())(declval<_Args>()...)) invoke(_Object* __Object,_Args... __args){
        //return __Object->*__fn(__args...);
        return (__Object->*__fn)(__args...);
    }

    template<typename T>
    void tprint(T a){cout<<a<<endl;}
};

template<typename _Tp>
struct _type2value
{
    static _Tp delegate();
};

template<typename _Tp>
_Tp type2value()
{
    return _type2value<_Tp>::delegate();
};

class C{
public:
    int a();
    int b(){return 0;};

    static int d();
};


int main(){

    A* a1 = new A();
    Method<decltype(&A::af1)> amethod;
    amethod.__fn = &A::af1;
    auto ret = amethod.invoke(a1,10,'8',10.0f);
    // amethod.print();
    // amethod.tprint(10);

    auto funcaf1 = &A::af1;
    std::invoke(funcaf1,a1,10,'8',10.0f);
    (a1->*funcaf1)(10,'8',10.0f);

    decltype((a1->*funcaf1)(10,'8',10.0f)) a=10;

    C c;
    //c.a();
    c.b();

    //C::d();

    //auto t2v=type2value<int>();

    decltype(type2value<int>()) t2v2;
    return 0;
    
}