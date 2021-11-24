#include <iostream>
// 析构函数 为protected:
// 则只能子类里调用析构，即这个类型只能被继承来使用，不能单独使用

// 析构函数为 private:
// 则这个类型只能被自身访问，即内存的回收必须有其他成员函数来完成，其他成员来 delete self