#include<iostream>

enum Color{
    Red,
    Blue,
    Green,
    Count,
};

int main_enum(){
    std::cout<<"hello enum"<<std::endl;
{
    //Color c1 = 0;
    Color c2 = Red;
    Color c3 = Color::Blue;
    int c4 = Color::Green;
    std::cout<<c3<<std::endl;
    std::cout<<c4<<std::endl;
}

    std::cout<<"bye enum"<<std::endl;
 
    return 0;
}