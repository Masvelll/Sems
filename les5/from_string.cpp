#include<iostream>
#include<string>
#include<sstream>
#include<exception>

struct bad_from_string: std::exception {
    explicit bad_from_string() : err_msg("Can't convert from string") {};
    explicit bad_from_string(char const * s) : err_msg(s) {}; 

    char const *what() const noexcept override { return err_msg; }

    char const * err_msg;
};

template<typename T>
T from_string(std::string const& s) {


    std::istringstream mystream;
    mystream.str(s);
    T value;
    mystream >> std::noskipws >> value;
    std::cout << mystream.eof() << '\n';
    if (mystream.eof() == false) throw bad_from_string();
    return value;

}

int main() {

    std::string s1("123");
    int    a1 = from_string<int>   (s1); // a1 = 123
    double b1 = from_string<double>(s1); // b1 = 123.0
    std::string c1 = from_string<std::string>(s1); // c1 = "123"

    std::string s2("12.3");
    //int    a2 = from_string<int>   (s2); // исключение
    double b2 = from_string<double>(s2); // b2 = 12.3
    std::string c2 = from_string<std::string>(s2); // c2 = "12.3"

    std::string s3("abc");
    //int    a3 = from_string<int>   (s3); // исключение
    double b3 = from_string<double>(s3); // исключение
    std::string c3 = from_string<std::string>(s3); // c3 = "abc"



    return 0;
}
