#include <iostream>
#include <cassert>

template <unsigned N>
double apply(double (*f)(double), double value) {
    return apply<N-1>(*f, f(value));
};

template <>
double apply<1>(double (*f)(double), double value) {
    return f(value);
};


double sqr(double x) {
    return x * x;
}
int main() {
    assert(1.0 == apply<3>(sqr, 1.0));
    assert(256.0 == apply<3>(sqr, 2.0));
    return 0;
}
