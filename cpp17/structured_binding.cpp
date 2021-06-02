#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Student{
    int id;
    string name;
};

int main(){
    // get value from struct.
    auto& [id, name] = Student{3,"junjie"};

    // iterator map
    map<int, string> s;
    for(const auto& [id, name] : s){
        cout << id << name << endl;
    }

}