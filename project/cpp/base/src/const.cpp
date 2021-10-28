#include <iostream>
#include<vector>
using namespace std;
namespace myconst{
    class A{
    public:
        int a1;
        float a2;
    public:
        A(int _a1,float _a2):a1(_a1),a2(_a2){}
        void print(){
            cout<<"A:"<<a1<<";"<<a2<<endl;
        }

        const void cprint() const{
            cout<<"A:"<<a1<<";"<<a2<<endl;
        }
    };

    class B{
    public:
        int b1;
        float b2;
    public:
        B(int _b1,float _b2):b1(_b1),b2(_b2){}
        void print(){
            cout<<"B:"<<b1<<";"<<b2<<endl;
        }
    };

}


int main_const(){
    const vector<myconst::A> va11{{1,1.0f},{2,2.0f},{3,3.0f},{4,4.0f}};
    //va11.push_back({4,4.0f});
    myconst::A a11 = va11[0];
    a11.print();

    myconst::A* a12= const_cast<myconst::A*>(&va11[1]);
    va11[1].cprint();
    a12->print();
    //va11[1].a1 = 22;
    a12->a1 = 22;
    va11[1].cprint();
    a12->print();

    const myconst::A* a13 = &va11[2];
    //a13->a1 = 222;
    a13 = &va11[3];
    //myconst::A* const a14 = &vall[2];

    myconst::A a14{14,14.0f};
    a13 = &a14;
    //a13->a1 = 13;

    

    vector<myconst::A> va12{{1,1.0f},{2,2.0f},{3,3.0f}};
    myconst::A a21 = va12[0];

    // va11 = {{1,1.0f}};
    // va11 = va12;

    vector<myconst::A> va13{{1,1.0f},{2,2.0f},{3,3.0f}};
    va13 = va12;

    return 0;
}