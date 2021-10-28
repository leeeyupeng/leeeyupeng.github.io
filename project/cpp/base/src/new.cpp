#include<iostream>

using namespace std;

class Base{
public:
    int base = 0;
public:
    Base(int _base):base(_base){
        cout<<"Base:"<<base<<endl;
    }

    virtual void print(){
        cout<<"Base print:"<<base<<endl;
    }
    void foo(){
        cout<<"Base foo:"<<base<<endl;
    }

    static void* operator new(size_t size){
        cout<<"Base:"<<"static void* operator new(size_t size)"<<endl;
        void* ptr = malloc(size);
        return ptr;
    }

    static void operator delete(void* pdead,size_t size){
        cout<<"Base:"<<"static void operator delete(void* pdead,size_t size)"<<endl;
        free(pdead);
        pdead = nullptr;
        return;
    }

    static void* operator new(size_t size,void* ptr){
        cout<<"Base:"<<"static void* operator new(size_t size,void* ptr)"<<endl;
        return ptr;
    }
};


class BaseA:public Base{
public:
    int a1=0;
public:
    BaseA(int _a1,int _base):Base(_base),a1(_a1){}
    ~BaseA(){}
    virtual void print(){
        //Base::print();
        this->Base::print();
        cout<<"BaseA print:"<<a1<<endl;
    }
};

int main_new(){
    Base* base1 = new Base(1);
    
    Base* base2 = (Base*) ::operator new(sizeof(Base));

    void* ptr3 = ::operator new(sizeof(Base));
    Base* base3 = (Base*) ::operator new(sizeof(Base),ptr3);

    void* ptr4 = ::operator new(sizeof(Base));

    Base* base4 = new(ptr4)Base(4);

    void* ptr5 = ::operator new(sizeof(Base));
    Base* base5 = new(ptr5)Base(5);

    Base* base6 = ::new Base(6);

    // Base* base7 = ::operator new Base(7);

    BaseA* a1 = new BaseA(1,1);
    // a1->print();

    cout<<"sizeof(void*)" << sizeof(void*) <<endl;
    cout<<"sizeof(Base):"<<sizeof(Base)<<endl;
    cout<<"sizeof(BaseA):"<<sizeof(BaseA)<<endl;

    void* ptr12 = malloc(sizeof(BaseA));
    Base* a2 = (BaseA*) ::operator new(sizeof(BaseA),ptr12);
    //a2->print();

    BaseA* a3 = new BaseA(3,3);

    void* ptra1 = &a3->a1;
    void* ptrbase = &a3->base;

    void* ptr14 = malloc(sizeof(BaseA));
    Base* a4 = (BaseA*) new(ptr14)BaseA(4,4);
    a4->print();

    void* ptr15 = malloc(sizeof(BaseA));
    Base* a5 = (BaseA*) new(ptr15)BaseA(4,4);


    void* ptr16 = malloc(sizeof(BaseA));
    //BaseA* a6 = (BaseA*) ::operator new(sizeof(BaseA),ptr16);
    BaseA* a6 = (BaseA*) new(ptr16)BaseA(6,6);
    //a6->BaseA::BaseA();

    a6->BaseA::~BaseA();
    a6 = nullptr;
    free(ptr16);
    ptr16 = nullptr;

    return 0;
}