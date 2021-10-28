#include<iostream>
#include<vector>
#include<string>


#include"LOG.hpp"

class RValue{
public:
    RValue(){
        std::cout<<__func__<<std::endl;
        std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
        LOG("RValue()");
    }
    ~RValue(){
        std::cout<<__func__<<std::endl;
        std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
        LOG("~RValue()");
    }

    // RValue(RValue rv){
    //     std::cout<<"RValue(Rvalue c)"<<std::endl;
    // }
    RValue(RValue & rv){
        //std::cout<<"RValue(Rvalue &c)"<<std::endl;
        std::cout<<__func__<<std::endl;
        std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
        LOG("RValue(RValue & rv)");
    }
    RValue(RValue && rv){
        //std::cout<<"RValue(RValue && rv)"<<std::endl;
        std::cout<<__func__<<std::endl;
        std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
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
int main(){
    LOG("Hello rvalue");

{
    RValue rv1;
    RValue rv2 = RValue();
    f1(rv1);
    f1(std::move(rv1));        std::cout<<__FILE__<<":"<<__LINE__<<std::endl;
    //f2(std::move(rv1));
    RValue && rv3 = std::move(rv1);
    f1(rv3);
    f2(rv3);
    f3((RValue&&)rv3);
    f3(std::move(rv1));

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

}
    LOG("Bye rvalue");

    return 0;
}