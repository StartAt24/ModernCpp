#include <thread>
#include <future>
#include <chrono>
#include <mutex>
#include <iostream>
// #include <

using namespace std;
mutex output_lock;

void func(const char* name){
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> guard(output_lock);
    cout << " I am thread " <<name << "\n";
}

class scoped_thread{
public:
    template<typename... Arg>
    scoped_thread(Arg&&... arg):thread_(std::forward<Arg>(arg)...){}
    scoped_thread(scoped_thread&& other):thread_(std::move(other.thread_)){}
    scoped_thread(const scoped_thread&) = delete;
    ~scoped_thread(){
        if(thread_.joinable())
            thread_.join();
    }
private:
    thread thread_;
};

// int work(){
//     this_thread::sleep_for(chrono::seconds{3});
//     return 38;
// }

// void work(promise<int> prom){
//     this_thread::sleep_for(chrono::seconds{3});
//     prom.set_value(22);
// }
int work(){
    this_thread::sleep_for(chrono::seconds{3});
    return 33;
}

int main(){
    // thread t1{func, "A"};
    // thread t2{func, "B"};
    // t1.join();
    // t2.join();
    // auto fut = async(launch::async, work);
    // promise<int> prom;
    // auto fut = prom.get_future();
    // scoped_thread th{work, move(prom)};
    packaged_task<decltype(work)> task{work};
    auto fut = task.get_future();
    scoped_thread th{move(task)};
    // this_thread::sleep_for(chrono::seconds{1});
    cout << "Waiting for response.\n";
    cout << "Answer: " <<fut.get() << "\n";
}
