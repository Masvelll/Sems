#include <iostream>

template<int N, int i = 2, bool less = true>
struct is_prime
{

    static const bool lesser = (i * i <= N);
    static const bool prime = is_prime<N, i + 1, lesser>::prime && (N % i != 0); 
    

};


template<>
struct is_prime<2, 2>
{
    static const bool prime = true;
};

template<int N, int i>
struct is_prime<N, i, false> {
    static const bool prime = true;
};

int main() {

    std::cout << is_prime<3>::prime << '\n';
    std::cout << is_prime<4>::prime << '\n';
    std::cout << is_prime<10>::prime << '\n';
    std::cout << is_prime<11>::prime << '\n';

    return 0;
}
