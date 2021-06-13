#include <iostream>
#include <mutex>
using namespace std;
mutex condition_lock;

int main(){
    int a = 3;
    if(lock_guard<mutex> lg(condition_lock); a<3){
        cout << "a less than" << 3 << endl;
    }

    

}