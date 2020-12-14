#include <iostream>
#include <functional>
#include <algorithm>
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
    return 0;
}
