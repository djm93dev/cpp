#include <iostream>

class num {
    int value = 0;
public:
    num( int x = 0 ) : value(x) {}
    int getvalue() const { return value; }
    void setvalue( int x ) { value = x; }
    num & operator ++ ();
    num operator ++ (int);
    num & operator -- ();
    num operator -- (int);
};


// pre-increment
num & num::operator ++ () {
    std::cout << "pre-increment: ";
    value += 1;
    return *this;
}

// post-increment
num num::operator ++ (int) {
    std::cout << "post-increment: ";
    num temp = *this;
    value += 1;
    return temp;
}

// pre-decrement
num & num::operator -- () {
    std::cout << "pre-decrement: ";
    value -= 1;
    return *this;
}

// post-decrement
num num::operator -- (int) {
    std::cout << "post-decrement: ";
    num temp = *this;
    value -= 1;
    return temp;
}

std::ostream & operator << (std::ostream & o, const num & n) {
    return o << (n.getvalue());
}

int main()
{
    num n(42);
    std::cout << "value is " << n << std::endl;
    std::cout << "value is " << ++n << std::endl; // pre-increment
    std::cout << "value is " << n++ << std::endl; // post-increment
    std::cout << "value is " << n << std::endl;
    return 0;
}
