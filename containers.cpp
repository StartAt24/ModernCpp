#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

template<class T>
void PrintVec(const vector<T>& in){
    for(const auto& i: in){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v{13, 6, 4, 11, 29};
    PrintVec<int>(v);

    sort(v.begin(), v.end());
    PrintVec<int>(v);

    sort(v.begin(), v.end(), greater<int>());
    PrintVec<int>(v);
    cout << hex;

    auto hp = hash<int*>();
    cout << "hash(nullptr) = "<< hp(nullptr) <<endl;
    cout << "hash(v.data()) = "<< hp(v.data()) <<endl;
    cout << "v.data() = "<< static_cast<void*>(v.data()) <<endl;

    auto hs = hash<string>();
    cout << "hash(\"hello\")" << hs(string("hello")) <<endl;
    cout << "hash(\"hellp\")" << hs(string("hellp")) <<endl;
    cout << "----------" << endl;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({1,1});
    q.push({2,2});
    q.push({0,3});
    q.push({9,4});
    while(!q.empty()){
        cout << q.top().first << ',' << q.top().second << endl;
        q.pop();
    }
    return 0;
}
