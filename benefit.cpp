#include <string>
class length{
public:
enum unit{
    metre=0,
    kilometre,
    millimetre,
    centimetre,
    inch,
    foot,
    yard,
    mile
    };

public:
    length operator+(length rhs){
        return length(this->value_ + rhs.value_);
    }
    explicit length(double v, unit u = unit::metre){
        value_ = v*factors_[u];
    }


private:
    double value_;
    double factors_[8] = {
        1.0, 1000.0, 1e-3,
        1e-2, 0.0254, 0.3048,
        0.9144, 1609.344};
};

length operator"" _m(long double v){
    return length(v ,length::unit::metre);
}

length operator"" _cm(long double v){
    return length(v ,length::unit::centimetre);
}

int main(){
    auto s = 1.0_m + 10.0_cm;
    return 0;
}