#include<stdio.h>
#define LOG(...)  {\
    fprintf(stderr,"%s:%d\n",__FILE__,__LINE__);\
    fprintf(stderr,__VA_ARGS__);\
    fprintf(stderr,"\n");\
}