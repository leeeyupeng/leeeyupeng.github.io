#include<iostream>
#include<vector>
using namespace std;
#include<type_traits>

#define MAX 100
struct _lt_true_type{};
// void func(_lt__true_type){

// };
int main()
{
    vector<int> vi;
    auto ite = vi.begin();
    vector<int>::iterator ite2;
    // uninitialized_fill_n
    // __is_trivial
    //__is_trivial(__true_type)

    auto is_t = __is_trivial(_lt_true_type);
    int a = 10;
    auto ret = is_trivial<true_type>::value;
    int a = MAX;
    // true_type::value;
    // true_type::value_type
    
}