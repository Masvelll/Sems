#include <iostream>

template<typename... Args>
struct tuple;

template<typename Head, typename... Tail>
    struct tuple<Head, Tail...> : tuple<Tail...>
    {
        tuple(Head h, Tail... tail)
            : tuple<Tail...>(tail...), head_(h)
        {}
        typedef tuple<Tail...> base_type;
        typedef Head           value_type;
        
        base_type& base = static_cast<base_type&>(*this);
        Head       head_;
    };

template<>
    struct tuple<>
    {};

int main() {

    tuple<int, int, int> t(12, 2, 89);
    std::cout << t.head_ << "\n";

    return 0;
}

