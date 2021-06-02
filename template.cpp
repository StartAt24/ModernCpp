#include <iostream>
#include <vector>
using namespace std;

#if 0
template <int n>
struct factorial{
    static const int value =
        n* factorial<n-1>::value;
};

template<>
struct factorial<0>{
    static const int value =1;
};

#endif

template<bool cond, typename Then, typename Else>
struct If;

template<typename Then, typename Else>
struct If<true, Then, Else>{
    typedef Then type;
};

template<typename Then, typename Else>
struct If<false, Then, Else>{
    typedef Else type;
};

template<bool condition, typename Body>
struct WhileLoop;

template<typename Body>
struct WhileLoop<true, Body>{
    typedef typename WhileLoop<
        Body::cond_value,
        typename Body::next_type>::type
        type;
};

template<typename Body>
struct WhileLoop<false, Body>{
    typedef typename WhileLoop<
        Body::cond_value,
        Body>::type
        type;
};

template <typename T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant type;
};

// template<int result, int n>
// struct SumLoop{
//     static const bool cond_value = n!=0;
//     static const int res_value = result;
//     typedef integral_constant<int, res_value> res_type;
//     typedef SumLoop<result +n, n-1> next_type;
// };

template <int result, int n>
struct SumLoop {
  static const bool cond_value =
    n != 0;
  static const int res_value =
    result;
  typedef integral_constant<
    int, res_value>
    res_type;
  typedef SumLoop<result + n, n - 1>
    next_type;
};

template <int n>
struct Sum {
  typedef SumLoop<0, n> type;
};

template <template<typename, typename> class OutContainer=vector, typename F, class R>
auto fmap(F&& f, R&& inputs){
    typedef decay_t<decltype(f(*inputs.begin()))> result_type;
    OutContainer<result_type, allocator<result_type>> result;
    for(auto && item: inputs){
        result.push_back(f(item));
    }
    return result;
}

int main(){
    // cout << factorial<10>::value << endl;


    return 0;
}