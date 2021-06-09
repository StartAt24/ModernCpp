#include <iostream>
#include <cassert>
using namespace std;

class Point1{
public:
float x;
float y;
};

class Point2{
public:
float x;
float y;
};

template<class class_type, class data_type1, class data_type2>
char* access_order(data_type1 class_type::*mem1, data_type2 class_type::*mem2)
{
    assert(mem1 != mem2);
    return mem1 < mem2? "member 1 occurs first": "member 2 occurs first";
}


int main(){
    cout << access_order(&Point2::x, &Point2::y);
    return 0;
}