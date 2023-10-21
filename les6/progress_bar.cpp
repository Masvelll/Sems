#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

int main() {


    for (auto i = 0; i < 100; i ++) {

        std::this_thread::sleep_for(50ms);
        std::cout << '[';
        if (i != 0) std::cout << std::setw(i) << std::setfill('#') << '.';
        else std::cout << std::setw(100 - i) << std::setfill('.') << ']';
        if (i != 0) std::cout << std::setw(100 - i) << std::setfill('.') << ']';
        std:: cout << ' ' << i << '%';
        std::cout << '\r';
        std::cout.flush();
    }
    

    return 0;
}