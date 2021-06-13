#include <iostream>
#include <map>
#include <string>
#include <mutex>
using namespace std;
mutex condition_lock;

int main(){
    int a = 3;
    if(lock_guard<mutex> lg(condition_lock); a<3){
        cout << "a less than" << 3 << endl;
    }

    std::map<string, int> coll;
    if(auto [pos, ok] = coll.insert({"new", 23}); !ok){
        const auto&[key, val] = *pos;
        cout << "already in there:" << key << endl;
    }


}