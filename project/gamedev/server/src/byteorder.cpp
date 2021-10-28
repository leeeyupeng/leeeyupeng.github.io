#include<iostream>

#include<math.h>
#include<memory.h>
#include<limits.h>
using namespace std;
union byteorder
{
    int value;
    char cc[4];
};

void uint2big(unsigned int value,unsigned char buff[]){
    buff[0] = value&0xFF;
    buff[1] = (value>>8)&0xFF;
    buff[2] = (value>>16)&0xFF;
    buff[3] = (value>>24)&0xFF;
}
void big2uint(unsigned char buff[],unsigned int &value){
    value|=buff[3];
    value<<=8;
    value|=buff[2];
    value<<=8;
    value|=buff[1];
    value<<=8;
    value|=buff[0];
}

void int2big(int value,char buff[]){
    byteorder bo;
    bo.value = value;

    buff[0] = 0b00000000;
    buff[1] = 0b00000000;
    buff[2] = 0b00000000;
    buff[3] = 0b00000000;

    buff[3] |= (value&0xFF);
    
    value>>=8;
    bo.value = value;
    buff[2] |= (value&0xFF);
    value>>=8;
    bo.value = value;
    buff[1] |= (value&0xFF);
    value>>=8;
    bo.value = value;
    buff[0] |= (value&0xFF);
}
void big2int(char buff[],int &value){
    value = 0;
    value|=(unsigned char)buff[0];
    value<<=8;
    value|=(unsigned char)buff[1];
    value<<=8;
    value|=(unsigned char)buff[2];
    value<<=8;
    value|=(unsigned char)buff[3];
}
int main_byteorder(){
    byteorder bo;
    bo.value = 0x01020304;
    cout<<bo.cc[0]+'0'<<"-"<<bo.cc[1]+'0'<<"-"<<bo.cc[2]+'0'<<"-"<<bo.cc[3]+'0'<<endl;

    {
        unsigned int value = rand();
        bo.value = value;
        unsigned char buff[4];
        buff[0] = value&0xFF;
        buff[1] = (value>>8)&0xFF;
        buff[2] = (value>>16)&0xFF;
        buff[3] = (value>>24)&0xFF;

        unsigned int vvalue = 0x0;
        vvalue+=buff[3];
        vvalue<<=8;
        vvalue+=buff[2];
        vvalue<<=8;
        vvalue+=buff[1];
        vvalue<<=8;
        vvalue+=buff[0];
        cout<<value<<"-"<<vvalue<<endl;
    }

    {
        int counter = 10000;
        while(counter>=0){
            counter--;
            unsigned int value = rand();
            unsigned char buff[4];
            uint2big(value,buff);
            unsigned int vvalue = 0;
            big2uint(buff,vvalue);
            cout<<value<<"-"<<vvalue<<endl;
        }
    }

    {
        int value = 0xFA971524;
        char buff[4];
        int2big(value,buff);
        int vvalue = 0;
        big2int(buff,vvalue);
        cout<<value<<"-"<<vvalue<<endl;
    }
    {
        int value = -1;
        char buff[4];
        int2big(value,buff);
        int vvalue = 0;
        big2int(buff,vvalue);
        cout<<value<<"-"<<vvalue<<endl;
    }

    {
        int counter = 10000;
        while(counter>=0){
            counter--;
            int value = rand() - (INT_MAX>>1);
            char buff[4];
            int2big(value,buff);
            int vvalue = 0;
            big2int(buff,vvalue);
            cout<<value<<"-"<<vvalue<<endl;
        }
    }
    return 0;
}