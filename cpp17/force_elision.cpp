#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

class Base{

};

class Test: public Base{
public:
    Test(){
        cout << "Test construct..\n";
    }
    ~Test(){
        cout << "Test deconstruct..\n";
    }
    Test(const Test& other){
        cout << "Copy construct\n";
    }
    Test& operator=(const Test& other){
        cout << "operator =\n";
        return *this;
    }
    Test(Test&& other){
        cout << "Move construct\n";
    }
    Test& operator=(Test&& other){
        cout << "operator = move\n";
        return *this;
    }

private:
    int a;
};

class Test2: public Base{
public:
    Test2(){
        cout << "Test2 construct..\n";
    }
    ~Test2(){
        cout << "Test2 deconstruct..\n";
    }
    Test2(const Test2& other){
        cout << "Copy2 construct\n";
    }
    Test2& operator=(const Test2& other){
        cout << "operator2 =\n";
        return *this;
    }
    Test2(Test2&& other){
        cout << "Move2 construct\n";
    }
    Test2& operator=(Test2&& other){
        cout << "operator2 = move\n";
        return *this;
    }

private:
    int a;
};

Base* foo(bool flag){
    if(flag){
        return new Test();
    }else{
        return new Test2();
    }
}

Test foo2(Test& in){
    cout << "foo2 lvalue...\n";
    return in;
}

Test foo2(Test&& in){
    cout << "foo2 prvalue...\n";
    return in;
}

void fold(Test&& in){
    foo2(std::forward<Test>(in));
}

int main(){
    bool s;
    cin >> s;
    foo(s);
    cout << "-----\n";
    Test in;
    auto b = foo2(in);
    cout << "-----\n";
    fold(std::move(in));
}