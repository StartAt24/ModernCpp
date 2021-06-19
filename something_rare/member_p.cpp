#include <iostream>
#include <stdio.h>

class A{
    public:
    int a;
    int b;
};
class B:public A{
    public:
    int x;
};

int main(){
   printf("%p\n", &A :: a);
   auto s = &A::a;
   std::cout << &A::a << std::endl;
   std::cout << &A::b << std::endl;
   std::cout << &B::x << std::endl;
   return 0;
}