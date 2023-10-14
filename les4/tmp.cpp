#include <iostream>


template <int ...List>
struct IntList;

template <int Head, int... Tail>
struct IntList<Head, Tail...>
{
    
    using tail = IntList<Tail...>;
    static const int head = Head;

};

template<>
struct IntList<> {};

template<int I, int Head, int... List>
struct getter {
    static const int value = getter<I-1, List...>::value;

};

template<int Head, int... List>
struct getter<0, Head, List...> {
    using ints = IntList<Head, List...>;
    static const int value = ints::head;
};

template<int I, typename IntList>
struct get {
    static const int value = getter<I, IntList::head, IntList::tail>::value;
};

using myints = IntList<1, 2, 3, 4, 5>;


int main() {

    std::cout << getter<3, 1, 2, 3, 4, 5>::value << '\n';
    //std::cout << get<3, myints>::value << '\n';
    std::cout << myints::tail::head << '\n';

    return 0;
}