#include <iostream>

template <typename T>
class Array
{
public: 

    explicit Array(size_t size, const T& value): m_size(size){
        m_data = new char[m_size * sizeof(T)];

        for (int i = 0; i < m_size; i++) { 
            new (m_data + sizeof(T) * i) T(value);
        } 
    };


    Array(const Array & other): m_size(other.size()){

        m_data = new char[m_size * sizeof(T)] ;

        for (int i = 0; i < m_size; i++) { 
            new(m_data + sizeof(T) * i) T(other[i]);
        } 

    };

    Array(Array && other): m_size(0), m_data(nullptr){
        
        std::swap(m_data, other.m_data);
        std::swap(m_size, other.m_size);

    }

    ~Array() { 
        for (int i = 0; i < m_size; i++) {
            reinterpret_cast<T *>(m_data + i*sizeof(T))->~T();
            
        }
        delete[] m_data;
    }

    Array& operator=(const Array & other) {

        Array<T> tmp(other);
        std::swap(tmp.m_size, m_size);
        std::swap(tmp.m_data, m_data);

        return *this;
    };

    Array& operator=(Array && other) {
        
        Array<T> tmp(other);

        std::swap(tmp.m_size, m_size);
        std::swap(tmp.m_data, m_data);

        return *this;
    }

    size_t size() const { return m_size; }

    T& operator[](size_t idx) {
        return reinterpret_cast<T *>(m_data)[idx];
    };
    const T& operator[](size_t idx) const{
        return reinterpret_cast<T *>(m_data)[idx];
    };

    void show(){
        for (int i = 0; i < m_size; i++) { std::cout << m_data[i] << " "; }
        std::cout << "\n";
    }

    
    
private:
    size_t m_size; 
    char * m_data;

};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Array<T>& arr) {
        for (int i = 0; i < arr.size(); i++) { os << arr[i] << " "; }
        os << "\n";
        return os;
    }

struct S {
    S() = delete;
    S(const S& o) {
        size = o.size;
        d = new int[size];
        for (int i = 0; i < size; i++) { d[i] = o.d[i]; }
    };
    S& operator = (const S&) = delete;
    explicit S(int s) { d = new int[s]; size = s; }
    ~S() {delete [] d;}
    int * d;
    size_t size;
};

int main() {

    size_t s = 3;
    S exmp = S(5);
    Array<S> arr_s(s, exmp);
    Array<S> arr_ctor_copy(arr_s);
    Array<S> arr_assign = arr_s;
    Array<S> arr_ctor_move(std::move(arr_s));
    Array<S> arr_move_assign = std::move(arr_ctor_copy);


    /*Array<int> arr(s, 2);
    std::cout << arr;
    arr[0] = 1;
    arr[1] = 5;
    std::cout << arr;
    Array<int> arr2(arr);
    Array<int> arr3(s, 3);
    std::cout << arr3;
    arr3 = std::move(arr);
    std::cout << arr3[4] << "\n";*/


    return 0;
}