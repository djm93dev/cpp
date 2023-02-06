#include <cstdio>

class A 
{
    int _value = 0; // private data member by default
public:
    void setv (const int a) { _value = a; } // public function member
    int getv () const { return _value; }; // public function member - const safe

};

int main()
{
    A a;
    a.setv(42);
    printf("value is %d\n", a.getv());

    const A b = a; // const object of class A
    printf("value is %d\n", b.getv());


    return 0;
}