#include<iostream>
#include"LOG.hpp"

/*
    1.string.data 返回堆地址，const char *类型
    2.string.c_str 返回堆地址，const char *类型
    3.string对象堆内存地址变化，之前返回的堆地址string.data和string.c_str会失效
    4.string对象析构，之前返回的堆地址string.data和string.c_str会失效
*/

/*
    1.通过std::move可以将string的内容转移
    2.转移后，s1的localbuf地址不会变化，s2的localbuf地址与s1不同
    3.如果s1的长度不超过localbuf，将s1的localbuf内容copy到s2的localbuf
    4.如果s1的长度超过localbuf，则s1分配的堆内存会转移给s2
    5.总体来说实现了资源的转移
*/

int main_string(){
    LOG("hello string");
// {
//         const char* c;
//         const char* cstr;
//     {
//         std::string str1{"hello string"};
//         cstr = str1.data();
//         std::cout<<(void*)cstr<<std::endl;
//         c = str1.c_str();
//         std::cout<<(void*)c<<std::endl;
//         char* ccstr1 = const_cast<char*>(c);
//         ccstr1[0] = 'b';
//         LOG(c);
//         LOGPP(str1);
//         str1 = "bye string";
//         LOG(c);

//         for(int i = 0; i < 1000; i ++){
//             str1.push_back('a' + rand() % 26);
//         }

//         cstr= str1.data();

//         std::cout<<(void*)cstr<<std::endl;
//     }

//     {
//         LOG(cstr);
//         LOG(c);
//     }
// }

{
    std::string s1{"hello string"};
    LOGPP(s1);
    LOG("s1 length:%d",s1.length());
    LOG("s1 capacity:%d",s1.capacity());
    std::cout<<(void*)s1.data()<<std::endl;
    for(int i = 0; i < 100000; i ++){
        s1.push_back('a' + rand() % 26);
    }
    std::cout<<(void*)s1.data()<<std::endl;
    LOG("s1 length:%d",s1.length());
    LOG("s1 capacity:%d",s1.capacity());
    std::string s2(std::move(s1));
    std::cout<<(void*)s1.data()<<std::endl;
    LOG("s1 length:%d",s1.length());
    LOG("s1 capacity:%d",s1.capacity());
    LOGPP(s1);
    LOGPP(s2);
    s1 = "bye string";
    LOGPP(s1);
    std::cout<<(void*)s1.data()<<std::endl;
    std::cout<<(void*)s2.data()<<std::endl;
}

    LOG("bye string");
    return 0;
}