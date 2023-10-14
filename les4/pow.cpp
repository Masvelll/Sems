#include <iostream>

template<int x, unsigned exp>
struct pow{

    static const int value = pow<x, exp - 1>::value * x;

};

template<int x>
struct pow<x, 1>{

    static const int value = x;

};

int main() {

    std::cout << pow<5, 2>::value << '\n';
    std::cout << pow<6, 3>::value << '\n';

    return 0;
}