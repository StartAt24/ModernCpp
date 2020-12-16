#include <iostream>
using namespace std;

class matrix{
public:
    matrix(size_t rows, size_t cols);
    // 半正则要求的构造
    matrix();
    matrix(const matrix&);
    matrix(matrix&&);
    // 半正则要求的赋值
    matrix& operator=(const matrix&);
    matrix& operator=(matrix&&);
        
    inline size_t cols() const {
        return 0;
    };
    inline size_t rows() const{
        return 0;
    };
    

private:
    size_t col_;
    size_t row_;
};

matrix operator*(const matrix& lhs, const matrix& rhs){
    if(lhs.cols() != rhs.rows()){
        throw runtime_error("sizes missmatch");
    }
    matrix result(lhs.rows(), rhs.cols());
    // specific operations
    return result;
}

int main(){
    return 0;
}