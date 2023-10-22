#include <iostream>
#include <charconv>
#include <array>

struct math_exeption: std::exception {
    explicit math_exeption() : err_msg("Math error") { }
    explicit math_exeption(char const * str) : err_msg(str) { }

    char const *what() const noexcept override { return err_msg; }

    char const * err_msg;

};

int divide(int x, int y) {

    try {
        if (y == 0) throw math_exeption("Division by zero error");
        return x / y;
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {

    divide(5, 0);

    return 0;
}


