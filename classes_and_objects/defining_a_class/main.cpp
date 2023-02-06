#include <cstdio>

class c1 
{
    int i = 0; // data members are private by default when using class vs struct
public:
    void setvalue( const int & );
    int getvalue() const;
};

void c1::setvalue( const int & value) 
    {
     i = value; 
    }
int c1::getvalue() const 
    {
     return i; 
    }


int main() 
{
    const int i = 47;
    c1 o1;
    o1.setvalue(i);
    printf("Value of i is %d\n", o1.getvalue());
    return 0;

}