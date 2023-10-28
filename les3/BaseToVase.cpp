#include <iostream>

struct Base { 
    virtual void call() { std::cout << "BASE"; }
}; 

struct D1 : Base { void call() override { std:: cout << "BASE D1"; }};

struct D2 : Base { void call() override { std:: cout << "BASE D2"; }}; 

struct D3 : D1, D2 { void call() override {std:: cout << "BASE D3"; }};

Base const * D1BaseToD2Base( Base const * base ) {
    return  static_cast<D2 const *>(static_cast<D3 const *>(static_cast<D1 const * >(base))); 
}

int main() {
    return 0;
}