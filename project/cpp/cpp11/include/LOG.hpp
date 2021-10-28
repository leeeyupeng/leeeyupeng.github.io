#pragma once
#include<stdio.h>
#include<iostream>

#define LOG(...)  {\
    fprintf(stderr,"%s:%d\n",__FILE__,__LINE__);\
    fprintf(stderr,__VA_ARGS__);\
    fprintf(stderr,"\n");\
}

#define LOGPP(...)  {\
    fprintf(stderr,"%s:%d\n",__FILE__,__LINE__);\
    std::cout<<__VA_ARGS__<<std::endl;\
}