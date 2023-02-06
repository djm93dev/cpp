#include <cstdio>
#include <vector>
#include <string>
#include <utility>


void message(const std::string & s) {
    puts(s.c_str());
    fflush(stdout);
}

void disp_t(std::vector<std::string> & v) {
    if(v.empty()) {
        puts("[empty]");
    } else {
        for( std::string s : v ) printf("%s ", s.c_str());
        puts("");
    }
    fflush(stdout);
}

template <typename T>
void swap(T & a, T & b) {
    message("swap()");
    T _tmp(std::move(a));
    a = std::move(b);
    b = std::move(_tmp);
}

int main() {
    std::vector<std::string> v1 = { "one", "two", "three", "four", "five" };
    std::vector<std::string> v2 = { "six", "seven", "eight", "nine", "ten" };
    
    disp_t(v1);
    disp_t(v2);
    
    // v2 = std::move(v1); // move function
    // auto v3 = std::move(v2); // move constructor
    ::swap(v1, v2); // swap function with the current scope resolution operator

    disp_t(v1);
    disp_t(v2);
    // disp_t(v3);

    return 0;
}