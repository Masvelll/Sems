#include <iostream>
#include <cassert>
#include <memory>
#include "./array.h"

template<typename T, std::size_t N>
class Grid final {

public:
    using value_type = T;
    using size_type = std::size_t;

private:
    size_type m_size;
    Array<Grid<T, N-1>> m_data;

public:
    template<typename... Args>
    Grid(size_type size, Args... subgrid_args):m_size(size), m_data(m_size, Grid<T, N-1>(subgrid_args...)){} ;

    template<typename... Args>
    T operator()(size_type idx, Args... args) const {
        return m_data[idx](args...);
    }

    Grid(): m_data(new Grid<T, N-1>()), m_size(1) {};

    const Grid<T, N-1>& operator[](size_type n) const {
        return m_data[n];
    }

    Grid(Grid<T, N> const& other)
    : m_size(other.m_size) 
    , m_data(m_size, Grid<T, N-1>())
    { 
        for (size_type i = 0; i < m_size; i++) { m_data[i] = other.m_data[i]; }
    }

    Grid<T, N>& operator=(const Grid<T, N>& other) {
        Grid<T, N> tmp(other);
        std::swap(tmp.m_data, m_data);
        std::swap(tmp.m_size, m_size);
        return *this;
    }



};

template<typename T>
class Grid<T, 1> final {

public:
    using value_type = T;
    using size_type = std::size_t;

private:
    size_type m_size;
    Array<T> m_data;

public:
    Grid(size_t size, T t) : m_size(size), m_data(size, t) {};

    Grid(): m_size(1), m_data(1, 0) {}

    T operator()(size_type idx) const {
        return m_data[idx];
    }

    Grid(Grid<T, 1> const& other)
    : m_size(other.m_size) 
    , m_data(m_size, T())
    { 
        for (size_type i = 0; i < m_size; i++) { m_data[i] = other.m_data[i]; }
    }

    Grid<T, 1>& operator=(const Grid<T, 1>& other) {
        Grid<T, 1> tmp(other);
        std::swap(tmp.m_data, m_data);
        std::swap(tmp.m_size, m_size);
        return *this;
    }

    

};


int main() {

    
    Grid<float, 3> const g3(2, 3, 4, 1.0f);
    assert(1.0f == g3(1, 1, 1));

    Grid<float, 2> g2(2, 5, 2.0f);
    assert(2.0f == g2(1, 1));

    g2 = g3[1];
    assert(1.0f == g2(1, 1));



    return 0;
}