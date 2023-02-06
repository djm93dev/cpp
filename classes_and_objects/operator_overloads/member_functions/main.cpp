#include <cstdio>
#include <iostream>


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
    Rational operator + ( const Rational & ) const;
    Rational operator - ( const Rational & ) const;
    Rational operator * ( const Rational & ) const;
    Rational operator / ( const Rational & ) const;
};

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator - ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * ( const Rational & rhs ) const {
    return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator / ( const Rational & rhs ) const {
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::~Rational() {
    _n = 0; _d = 1;
}

// for std::cout
std::ostream & operator << (std::ostream & o, const Rational & r) {
    if(r.denominator() == 1) return o << r.numerator();
    else return o << r.numerator() << '/' << r.denominator();
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
    return 0;
}