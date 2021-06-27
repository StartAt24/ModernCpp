#include <initializer_list>
#include <iostream>
#include <vector>
#include <array>

using namespace std;
// class CC{
//     private:
//     vector<int> _a;
//     int _b;
//     public:
//     // CC(initializer_list<int> a):_a(a){
//     // }
//     CC(int b):_b(b){}
// };

struct S{
int a;
int b;
// S(initializer_list<int> i){
//     cout << "call initializer" << endl;
//     a = *i.begin();
//     b =  *(i.end()-1);
// }
S(int s, int b){
    cout << "constructor\n";
    a = s;
    this->b = b;
}
S(){
    cout << "S constructor\n";
}
S(const S& other){
    cout << "S copy\n";
}

S(S&& other){
    cout << "S move\n";
}
~S(){
    cout << "de constructor\n";
}
void say(){
    cout << a << " " << b << endl;
}
};

int main(){
    // S s{1, 3};
    // S s{1, 3};
    // s.say();
    S s1{};
    S s2{};
    // vector<S> s3{{},{}};
    cout << "----\n";
    // std::initializer_list<S> a{move(s1), move(s1) };
    std::array<S, 3> b{move(s1), move(s2), move(s1)};
    // vector<S> s3;
    // s3.reserve(2);
    // s3.emplace_back(s1);
    // s3.emplace_back(s2);
}

// struct Foo
// {
// 	int x;
// 	int y;
// 	Foo(int, int){ cout << "Foo construction\n"; }
// };
 
// int main()
// {
// 	Foo foo{ 123, 321 };
// 	cout << foo.x << " " << foo.y<< "\n";
// 	return 0;
 
// }