#include <iostream>
#include <thread>

void f1(){
    for(int i = 0; i < 10000; i ++){
        std::cout<<i<<std::endl;
    }
}

class f2{
private:
    void exe()const{
        for(int i = 0; i < 10000; i ++){
            std::cout<<i<<std::endl;
        }
    }
public:
    void operator()() const
    {
        exe();
    }
};

struct  f3
{
    int val;
    f3(int _val):val(_val){}
    void operator()(){
        for(int i = 0; i < 10000; i ++){
            std::cout<<i<<std::endl;
        }
    }
};

int main(){
    std::cout<<"hello world,thread"<<std::endl;
// {
//     auto f = [](){
//         for(int i = 0; i < 10000; i ++){
//             std::cout<<i<<std::endl;
//         }
//     };

//     std::thread t(f1);
//     //t.join();
//     t.detach();
//     std::cout<<t.joinable()<<std::endl;
//     while(true){
//         if(!t.joinable()){break;}
//     }
// }

// {
//     f2 f;
//     std::thread t(f);
//     t.join();
// }

// {
//     std::thread t{f2()};
//     t.join();
// }

// {
//     std::cout<<"thread lambda start"<<std::endl;
//     std::thread t{[]{
//         for(int i = 0; i < 10000; i ++){
//             std::cout<<i<<std::endl;
//         }
//     }};

//     t.join();

//     std::cout<<"thread lambda end"<<std::endl;
// }


    std::cout<<"end thread" << std::endl;
    return 0;
}