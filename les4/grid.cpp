#include <iostream>

template<typename T>
class Grid final
{
public:
    using value_type = T;
    using size_type = unsigned;
private:
    T* const data;
    T* const m_data;
    size_type const y_size, x_size;
public:
    Grid(T *data , size_type y_size , size_type x_size)
    : data(data)
    , m_data(nullptr)
    , y_size(y_size)
    , x_size(x_size)
    {
    }

    explicit Grid(T const &t) :data(nullptr), m_data(new T[1]), y_size(1), x_size(1) {
        m_data[0] = t;
    }

    ~Grid() {
        delete[] m_data;
    }

    Grid(Grid<T> const&) = delete;
    Grid(Grid<T>&&) = delete;
    Grid<T>& operator=(Grid<T>&) = delete;
    Grid<T>& operator=(Grid<T>&&) = delete;

    T operator()(size_type y_idx , size_type x_idx) const
    {
        return data[y_idx * x_size + x_idx];
    }

    T& operator()(size_type y_idx, size_type x_idx)
    {
        return data [y_idx * x_size + x_idx];
    }

    Grid<T>& operator=(T const& t)
    {
        for (auto it = data, end = data + x_size * y_size; it != end; ++it) *it = t;
        return *this;
    }

    size_type get_y_size() const { return y_size; }
    size_type get_x_size() const { return x_size; }
} ;

int main() {

    int arr[9] = {1, 2, 3,
                  4, 5, 6,
                  7, 8, 9};
    Grid g1(arr, 3, 3);
    std::cout << g1(1, 2) << std::endl;

    Grid g2(5);
    std::cout << g2(0, 0) << std::endl;

    return 0;
}