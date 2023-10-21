#include <iostream>

template<typename T>
class Grid final
{
public:
    using value_type = T;
    using size_type = unsigned;
private:
    T* m_data;
    size_type y_size, x_size;

    void copy_data(T* const from, T* to){
        for (size_type y_idx = 0; y_idx < y_size; y_idx+=1) {
            for (size_type x_idx = 0; x_idx < x_size; x_idx+=1){
                to[y_size * y_idx + x_idx] = from[y_size * y_idx + x_idx];
            }
        }
    }

public:
    Grid(T* const data , size_type y_size , size_type x_size)
    : m_data(new T[y_size * x_size])
    , y_size(y_size)
    , x_size(x_size)
    {
        copy_data(data, m_data);
    }

    Grid(T const &t) : m_data(new T[1]), y_size(1), x_size(1) {
        m_data[0] = T(t);
    }

    Grid(size_type y_size, size_type x_size)
    : m_data(new T[y_size * x_size])
    , y_size(y_size)
    , x_size(x_size) {}

    Grid(size_type y_size, size_type x_size, T const &t)
    : m_data(new T[y_size * x_size])
    , y_size(y_size)
    , x_size(x_size) 
    {
        for (size_type i = 0; i < x_size * y_size; i++) { m_data[i] = T(t); }
    }


    ~Grid() {
        delete[] m_data;
    }

    

    Grid(Grid<T> const& other)
    : m_data(new T[other.x_size * other.y_size])
    , y_size(other.y_size)
    , x_size(other.x_size) 
    { 
        copy_data(other.m_data, m_data); 
    }

    Grid(Grid<T>&& other)
    : m_data(nullptr)
    , y_size(0)
    , x_size(0)
    {
        std::swap(other.m_data, m_data);
        std::swap(y_size, other.y_size);
        std::swap(x_size, other.x_size);
    }

    Grid<T>& operator=(const Grid<T>& other) {
        if (other == *this) { return *this; }
        Grid<T> tmp(other);
        std::swap(tmp.m_data, m_data);
        std::swap(tmp.x_size, x_size);
        std::swap(tmp.y_size, y_size);
        return *this;
    }

    Grid<T>& operator=(Grid<T>&& other) {
        if (other == *this) { return *this; }
        std::swap(other.m_data, m_data);
        std::swap(other.x_size, x_size);
        std::swap(other.y_size, y_size);
        return *this;
    }

    T operator()(size_type y_idx , size_type x_idx) const
    {
        return m_data[y_idx * x_size + x_idx];
    }

    T& operator()(size_type y_idx, size_type x_idx)
    {
        return m_data[y_idx * x_size + x_idx];
    }

    Grid<T>& operator=(T const& t)
    {
        for (auto it = m_data, end = m_data + x_size * y_size; it != end; ++it) *it = t;
        return *this;
    }

    size_type get_y_size() const { return y_size; }
    size_type get_x_size() const { return x_size; }
} ;

template<typename T>
    std::ostream &operator<<(std::ostream &os, const Grid<T>& g) {
            for (uint y_idx = 0; y_idx < g.get_y_size(); y_idx+=1) {
                for (uint x_idx = 0; x_idx < g.get_x_size(); x_idx+=1){
                    os << g(y_idx, x_idx) << " ";
            }
            os << "\n";
            }

            
            return os;
        }

int main() {

    int arr[9] = {1, 2, 3,
                  4, 5, 6,
                  7, 8, 9};
    Grid g1(arr, 3, 3);
    std::cout << g1(1, 2) << std::endl;

    Grid g2(5);
    std::cout << g2(0, 0) << std::endl;

    Grid g3 = g2;
    std::cout<<g1;

    Grid g4(std::move(g1));
    Grid g5(std::move(g1));

    Grid<int> g6(5, 6, 2);
    std::cout << g6;

    return 0;
}