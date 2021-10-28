#include<iostream>
#include<string>

using namespace std;

class operator_A{
public:
    int a1;
    int a2;
    float f1;
    string s1;
public:
    string gets1(){
        return this->s1;
    }
    operator_A& operator *(){
        cout<<"A& operator *()const{"<<endl;
        return *this;
    }

    operator_A* operator -> (){
        cout<<"A* operator ->() const{"<<endl;
        return this;
    }
};

template<typename T>
class operator_p{
public:
    T* t;
    operator_p(){
        t = new T();
    }
    T* operator -> (){
        cout<<"T* operator -> (){"<<endl;
        return t;
    }
};

int main_operator(){
    operator_A* a = new operator_A();
    a->a1 = 1;
    a->a2 = 2;
    a->s1="hello";

    string as1 = a->gets1();
    string as2 = (a->operator->())->gets1();

    operator_A a2;
    a2->a1 = 10;
    a2.a2 = 20;


    operator_p<operator_A> opa;
    
    string opas1 = opa->gets1();
    //operator_A* a2 = opa->t;

    operator_p<operator_A>* opa2 = new operator_p<operator_A>();
    //string opa2s1 = opa2->->()t;
    return 0;
}
