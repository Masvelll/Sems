#include <iostream>
#include <iomanip>
#include <fstream>

struct Table {
private:
    uint x_size, y_size;
    double* data = nullptr;
public:

    Table(uint x_size, uint y_size): x_size(x_size) y_size(y_size) {
        data =  data[y_size][x_size];
    }
};

int main() {

    std::fstream myfile;
    myfile.open("");

    return 0;
}