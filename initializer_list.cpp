#include <initializer_list>
#include <iostream>
#include <vector>

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
S(initializer_list<int> i){
    cout << "call initializer" << endl;
    a = *i.begin();
    b =  *(i.end()-1);
}
S(int s){
    cout << "constructor\n";
    a = s;
}
void say(){
    cout << a << " " << b << endl;
}
};

int main(){
    // S s{1, 3};
    S s{1};
    s.say();
}