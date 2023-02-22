#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
 
const double pi = std::acos(-1); // use std::numbers::pi in C++20
 
int main()
{
    // deprecated in C++11, removed in C++17
    auto f1 = std::bind1st(std::multiplies<double>(), pi / 180.);
 
    // C++11 replacement
    auto f2 = [](double a){ return a * pi / 180.; };
 
    for (double n : {0, 30, 45, 60, 90, 180})
        std::cout << n << "°\t" << std::fixed << "= "
                  << f1(n) << " rad (using binder)\t= "
                  << f2(n) << " rad (using lambda)\n"
                  << std::defaultfloat;
}