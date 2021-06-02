#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Student{
    int id;
    string name;
};

struct Base{
virtual void interface() = 0;
};

struct Derived: public Base{
virtual void interface() override{
    cout << "derived" << endl;
}
Derived(int id, string name){
    id_ = id;
    name_ = name;
}
int id_;
string name_;
};

int main(){
    // get value from struct.
    auto [id, name] = Student{3,"junjie"};

    // iterator map
    map<int, string> s;
    for(const auto& [id, name] : s){
        cout << id << name << endl;
    }

    // from virtual struct
    auto [id1, name1] = Derived{1, "hello"};
    cout << id1 << " " << name1 << endl;

}