#include<iostream>
#include<vector>
#include<string>

#include<type_traits>

#include"LOG.hpp"

class RValue{
public:
    RValue(){
        // std::cout<<__func__<<std::endl;
        // std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
        LOG("RValue()");
    }
    ~RValue(){
        // std::cout<<__func__<<std::endl;
        // std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
        LOG("~RValue()");
    }

    // RValue(RValue rv){
    //     std::cout<<"RValue(Rvalue c)"<<std::endl;
    // }
    RValue(RValue & rv){
        //std::cout<<"RValue(Rvalue &c)"<<std::endl;
        // std::cout<<__func__<<std::endl;
        // std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
        LOG("RValue(RValue & rv)");
    }
    RValue(RValue && rv){
        //std::cout<<"RValue(RValue && rv)"<<std::endl;
        // std::cout<<__func__<<std::endl;
        // std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
        LOG("RValue(RValue && rv)");
    }
};

void f1(RValue rv){
    std::cout<<"f1(RValue rv)"<<std::endl;
}
void f2(RValue &rv){
    std::cout<<"f2(RValue &rv)"<<std::endl;
}
void f3(RValue &&rv){
    std::cout<<"f3(RValue &&rv)"<<std::endl;
    //RValue rv3 = std::move(rv); 
}

std::vector<RValue> f4(){
    std::vector<RValue> v(3);
    return v;
}
std::vector<RValue> f5(){
    std::vector<RValue> v(3);
    return std::move(v);
}

RValue f6(){
    RValue v;
    int cnt = 0;
    for(int i = 0; i < 10; i ++){
        cnt +=i;
    }
    for(int i = 0; i < 10; i ++){
        cnt +=i;
    }
    for(int i = 0; i < 10; i ++){
        cnt +=i;
    }
    for(int i = 0; i < 10; i ++){
        cnt +=i;
    }
    for(int i = 0; i < 10; i ++){
        cnt +=i;
    }
    if(cnt==0){
        return f6();
    }
    return v;
}
RValue f7(){
    RValue v;
    return std::move(v);
}

template<class T>
bool is_rvalue(T&){return false;}
template<class T>
bool is_rvalue(T&&){return true;}

int main(){
    LOG("Hello rvalue");

{
    // RValue rv1;
    // RValue rv2 = RValue();
    // f1(rv1);
    // f1(std::move(rv1));        
    // std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
    // //f2(std::move(rv1));
    // RValue && rv3 = std::move(rv1);
    // f1(rv3);
    // f2(rv3);
    // f3((RValue&&)rv3);
    // f3(std::move(rv1));

}
{
    // RValue rv1;
    // //auto rv2 = std::move(rv1);
    // //auto rv2 = (RValue&&)rv1;
    
    // RValue &&rv3 = (RValue&&)rv1;
    // f3((RValue&&)rv3);
}

{
    // std::vector<int> v1(3,0);
    // std::cout<<"v1.size():"<<v1.size()<<std::endl;
    // std::vector<int> v2(std::move(v1));
    // std::cout<<"v1.size():"<<v1.size()<<std::endl;
    // std::cout<<"v2.size():"<<v2.size()<<std::endl;

    // std::vector<int> v3(v1);
    // std::cout<<"v1.size():"<<v1.size()<<std::endl;
    // std::cout<<"v3.size():"<<v3.size()<<std::endl;
}

{
    // std::vector<RValue> v1(3);
    // std::cout<<"v1.size():"<<v1.size()<<std::endl;
    // std::vector<RValue> v2(std::move(v1));
    // std::cout<<"v1.size():"<<v1.size()<<std::endl;
    // std::cout<<"v2.size():"<<v2.size()<<std::endl;
    // // std::vector<RValue> v3(v1);
    // // std::cout<<"v1.size():"<<v1.size()<<std::endl;
    // // std::cout<<"v3.size():"<<v3.size()<<std::endl;
}

{
    // std::string s1{"hello string"};
    // std::string s2(s1);
    // LOGPP(s1);
    // LOGPP(s2);
    // std::string s3=std::move(s1);
    // LOGPP(s1);
    // LOGPP(s3);
    // LOG(s3.c_str());

}

{
    // std::vector<RValue> v1 = f4();

    // std::vector<RValue> v2 = f5();
}

{
    RValue r1= f6();
    // LOG("Bye RValue r1= f6()");
    // //RValue r2= f7();

    // // RValue &r3 = f6();
}

{
    // LOGPP(std::is_rvalue_reference<int>::value);
    // LOGPP(std::is_rvalue_reference<int&&>::value);
    // int i1=10;
    // LOGPP(std::is_rvalue_reference<decltype(std::move(i1))>::value);
    // int && i2=std::move(i1);
    // LOGPP(std::is_rvalue_reference<decltype(i2)>::value);
}

{
    // LOGPP(is_rvalue(10));
    // int i1 = 10;
    // LOGPP(is_rvalue(i1));
    // LOGPP(is_rvalue(std::move(i1)));
    // int && i2 = std::move(i1);
    // LOGPP(is_rvalue(i2));    //i2不是右值引用
}

{
    // RValue r1;
    // RValue && r2 = std::move(r1);
    // std::cout<<(void*)&r1<<std::endl;
    // std::cout<<(void*)&r2<<std::endl;

}
    LOG("Bye rvalue");

    return 0;
}