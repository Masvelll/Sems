#include <iostream>
#include <cassert>

template<typename T, std::size_t N>
class Grid final {

public:
    using value_type = T;
    using size_type = std::size_t;

private:
    Grid<T, N-1>* m_subdata;
    size_type data_size;

public:
    template<typename... Args>
    Grid(size_type size, Args... subgrid_args): m_subdata(new Grid<T, N-1>(subgrid_args...)), data_size(size) {
        for (size_type i = 0; i < size; i++) { m_subdata[i] = Grid<T, N-1>(subgrid_args...); }
    } ;

    template<typename... Args>
    T operator()(size_type idx, Args... args) const {
        return m_subdata[idx](args...);
    }

};

template<typename T>
class Grid<T, 1> final {

public:
    using value_type = T;
    using size_type = std::size_t;

private:
    T* m_data;
    size_type data_size;

public:
    Grid(size_t size, T t) :m_data(new T[size]), data_size(size) {
        for (size_type i = 0; i < size; i++) { m_data[i] = T(t); }
    }

    T operator()(size_type idx) const {
        return m_data[idx];
    }

    // Grid(Grid<T> const& other)
    // : m_data(new T[other.data_size])
    // , data_size(other.data_size) 
    // { 
    //     copy_data(other.m_data, m_data); 
    // }

};


int main() {

    
    Grid<float, 3> const g3(2, 3, 4, 1.0f);
    assert(1.0f == g3(1, 1, 1));

    Grid<float, 2> g2(2, 5, 2.0f);
    assert(2.0f == g2(1, 1));

    // g2 = g3[1];
    // assert(1.0f == g2(1, 1));



    return 0;
}