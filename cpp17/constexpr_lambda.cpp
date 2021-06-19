#include <iostream>
#include <thread>
#include <string>
#include <array>
using namespace std;

class Data{
private:
    std::string name;
public:
    Data(const string& s):name(s){}
    auto startThreadWithCopyOfThis() const {
        using namespace std::literals;
        thread t([*this]{
            this_thread::sleep_for(3s);
            cout << name << '\n';
        });
        return t;
    }
};

int main(){
    auto s = [](auto val) constexpr{
        return val*val;
    };
    array<int, s(2)> arr;
    std::thread t;
    {
        Data d{"3"};
        t = d.startThreadWithCopyOfThis();
    }
    t.join();
}