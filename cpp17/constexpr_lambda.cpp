#include <iostream>
#include <array>
using namespace std;

int main(){
    auto s = [](auto val) constexpr{
        return val*val;
    };
    array<int, s(2)> arr;
}