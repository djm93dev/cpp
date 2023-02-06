#include <cstdio>
#include <iostream>
#include <string>

class Rational {
    int _n = 0;
    int _d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
    Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
    ~Rational ();
    int numerator() const { return _n; };
    int denominator() const { return _d; };
    Rational & operator = ( const Rational & );
    operator std::string() const;
};

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}


Rational::operator std::string() const {
    if(_d == 1) return std::to_string(_n);
    else return std::to_string(_n) + '/' + std::to_string(_d);
}

Rational operator + ( const Rational & lhs, const Rational & rhs ) {
    return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator - ( const Rational & lhs, const Rational & rhs ) {
    return Rational((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator * ( const Rational & lhs, const Rational & rhs ) {
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

Rational operator / ( const Rational & lhs, const Rational & rhs ) {
    return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

Rational::~Rational() {
    _n = 0; _d = 1;
}

// for std::cout
std::ostream & operator << (std::ostream & o, const Rational & r) {
    return o << std::string(r);
}

int main() {
    
    Rational a = 7;        // 7/1
    std::cout << "a is: " << a << std::endl;
    Rational b(5, 3);    // 5/3
    std::cout << "b is: " << b << std::endl;
    Rational c = b;        // copy constructor
    std::cout << "c is: " << c << std::endl;
    Rational d;            // default constructor
    std::cout << "d is: " << d << std::endl;
    d = c;                // assignment operator
    std::cout << "d is: " << d << std::endl;
    Rational & e = d;    // reference
    d = e;                // assignment to self!
    std::cout << "e is: " << e << std::endl;
    
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;


    std::string s = "Rational number is: ";
    s += b;
    std::cout << s << std::endl;


    return 0;
}
