#include <cstdio>

struct A // data members are public by default when using struct vs class
{
    int ia;
    const char * sb = "";
    int ic;
};


int main()
{
    A a;
    a.ia = 1;
    a.sb = "Hello";
    a.ic = 2;
    printf("a.ia = %d, a.sb = %s, a.ic = %d\n", a.ia, a.sb, a.ic);

    return 0;
}