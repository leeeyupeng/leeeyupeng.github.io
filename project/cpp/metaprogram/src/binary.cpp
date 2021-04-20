#include<iostream>
using namespace std;


template<unsigned long N>
struct binary
{
    static unsigned  const value = binary<N/10>::value * 2 + (N % 10);
};

template<>
struct binary<0>
{
    static unsigned const value=0;
};

// template<unsigned long N>
// struct binary
// {
//     static unsigned  value = binary<N/10>::value * 2 + (N % 10);
// };

// template<>
// struct binary<0>
// {
//     static unsigned value;
// };

int g1 = 10;
static int const g2 = 100;
int g3 = g1 * g2;

int main(){
    int a = 10;
    const int b = 100;
    const int c = 100*10;
    int d = 100 * 100;
    int e = 01000;

    unsigned v1 = binary<110>::value;
    unsigned v2 = binary<110>::value;

    // cout<<v1<<endl;
    // cout<<v2<<endl;
}