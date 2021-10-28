#include<iostream>
#include"lt/LOG.hpp"

#include"ltc/cfunc.h"
#include"externc.h"

#include"cfunc.h"
// int cfunc(int a,int b){
//     return a + (int)b;
// }
// int cfunc(int a,float b){
//     return a + (int)b;
// }

float sum(int a,float b){
    return a + b;
}
int main_externc(){
    LOG("hello extern C");
{
    int i1 = sum(1,2);
    LOG("i1=%d",i1);
}

{
    float i1 = sum(1,3.2f);
    LOG("i1=%d",i1);
}

{
    int i1 = csum(1,20);
    LOG("i1=%d",i1);
}

{
    int i1 = add(1,200);
    LOG("i1=%d",i1);
}
    LOG("bye extern C");
    return 0;
}