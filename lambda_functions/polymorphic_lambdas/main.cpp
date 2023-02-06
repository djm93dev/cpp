#include <iostream>
#include <typeinfo>


int main() {
    long n = 42;
    auto fp = [](const auto & n) ->auto { return n * 4; }; // auto type deduction
    auto x = fp(n);
    
    std::cout << "value of x: " << x << " type of x: " << typeid(x).name() << std::endl;
    
    return 0;
}