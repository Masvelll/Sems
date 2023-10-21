#include <iostream>
#include <iomanip>
#include <fstream>

int main() {

    std::fstream myfile;
    myfile.open("input.txt");

    if (myfile.is_open()) {
        std::string content;
        while (std::getline(myfile, content)) {
            double num = std::stod(content);
            std::cout << std::fixed << std::setprecision(3) << num  << std::endl;
        };
        
        
    }

    return 0;
}