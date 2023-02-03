#include <iostream>
using namespace std;

template <typename T>

int size_in_bits(const T& a) {
    return sizeof(a) *8;
}

int main () {
    int a = 0;
    char b = 'f';
    float c = 0.0;
    double d = 0.0;
    cout << size_in_bits(a) << endl;
    cout << size_in_bits(b) << endl;
    cout << size_in_bits(c) << endl;
    cout << size_in_bits(d) << endl;
    return 0;
}
