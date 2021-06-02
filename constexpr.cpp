#include <iostream>
#include <array>
using namespace std;
constexpr int sqrt(int n, bool flag){
    if(true)
        return n*n;
    else 
        return n;
    return 1; 
    // return n*n;
}

int main(){
    constexpr int size= sqrt(3, false);
    // int a[size];
    // constexpr bool flag = true;
    // array<int, sqrt(3, flag)> b;
    return 0;
}