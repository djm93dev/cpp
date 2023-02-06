#include <cstdio>


class c1
{
    int _value = 0;
    c1();
public:
    c1(const int & value) : _value(value) {} // implicit constructor
    // explicit c1(const int & value) : _value(value) {} // explicit constructor
    void setvalue(const int & value) { _value = value; }
    int getvalue() const { return _value; }
};

void func(const c1 & o)
{
    printf("value is %d\n", o.getvalue());
}

int main()
{
    c1 o = 'x'; // can convert char to int with class as long as the constructor only has one argument
    printf("value is %d\n", o.getvalue());
    func('x');
    return 0;
}