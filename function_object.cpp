#include <iostream>
#include <numeric>
#include <thread>
#include <sstream>
#include <array>
using namespace std;

struct adder{
    adder(int n) : n_(n){}
    int operator()(int x) const{
        return x+n_;
    }
    private:
    int n_;
};

int get_count(){
    static int count =0;
    return ++count;
}

class task{
    public:
    task(int data):data_(data){}
    auto lazy_launch(){
        return [this, count=get_count()]() mutable{
            ostringstream oss;
            oss << " Done work " << data_ << " (No. " << count <<")in thread"
            << this_thread::get_id()
            << "\n";
        msg_ = oss.str();
        calculate();
        };
    }
    void calculate(){
        this_thread::sleep_for(100ms);
        cout << msg_;
    }
    private:
    int data_;
    string msg_;
};


int main(){
    // auto add_2 = adder(2);
    // cout << add_2(3)<<"\n";

    // auto common_add = [](int a){
    //     return [a](int x){
    //         return a+x;
    //     };
    // };
    // cout << common_add(3)(2);
    // auto t = task{37};
    // thread t1{t.lazy_launch()};
    // thread t2{t.lazy_launch()};
    // t1.join();
    // t2.join();
    array<int, 5> a{1,2,3,4,5};
    auto s = accumulate(a.begin(), a.end(), 0, [](auto x, auto y){
        return x+y;
    });
    cout << s << endl;
}