#include <cstdio>
#define _FOO // define this to get 47 instead of 2
#include "conditional.h"

int main()
{
    printf("Number is %d\n", _NUMBER);
    return 0;
}