#include <iostream>
#include <charconv>
#include <array>

struct math_exeption: std::exception {
    explicit math_exeption(int line) : m_line(line){ }
    char const *what() const noexcept override {

        return m_line;
    }
    int m_line;

};

int divide(int x, int y) {

    try {
        throw math_exeption(__LINE__);
    }   catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    };

    if (y == 0) math_exeption(__LINE__);
    return x / y;
}

int main() {

    

    return 0;
}


