/* abs example
#include <iostream>
#include <cmath>

int main()
{
    std::cout << "abs(+3.0) = " << std::abs(+3.0) << '\n'
              << "abs(-3.0) = " << std::abs(-3.0) << '\n';
    // special values
    std::cout << "abs(-0.0) = " << std::abs(-0.0) << '\n'
              << "abs(-Inf) = " << std::abs(-INFINITY) << '\n'
              << "abs(-NaN) = " << std::abs(-NAN) << '\n';
}
*/


/* fmod example
#include <iostream>
#include <cmath>
#include <cfenv>
 
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "fmod(+5.1, +3.0) = " << std::fmod(5.1,3) << '\n'
              << "fmod(-5.1, +3.0) = " << std::fmod(-5.1,3) << '\n'
              << "fmod(+5.1, -3.0) = " << std::fmod(5.1,-3) << '\n'
              << "fmod(-5.1, -3.0) = " << std::fmod(-5.1,-3) << '\n';
 
    // special values
    std::cout << "fmod(+0.0, 1.0) = " << std::fmod(0, 1) << '\n'
              << "fmod(-0.0, 1.0) = " << std::fmod(-0.0, 1) << '\n'
              << "fmod(5.1, Inf) = " << std::fmod(5.1, INFINITY) << '\n';
 
    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "fmod(+5.1, 0) = " << std::fmod(5.1, 0) << '\n';
    if(std::fetestexcept(FE_INVALID))
        std::cout << "    FE_INVALID raised\n";
}
*/

/* remainder example
#include <iostream>
#include <cmath>
#include <cfenv>
 
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "remainder(+5.1, +3.0) = " << std::remainder(5.1,3) << '\n'
              << "remainder(-5.1, +3.0) = " << std::remainder(-5.1,3) << '\n'
              << "remainder(+5.1, -3.0) = " << std::remainder(5.1,-3) << '\n'
              << "remainder(-5.1, -3.0) = " << std::remainder(-5.1,-3) << '\n';
 
    // special values
    std::cout << "remainder(-0.0, 1.0) = " << std::remainder(-0.0, 1) << '\n'
              << "remainder(5.1, Inf) = " << std::remainder(5.1, INFINITY) << '\n';
 
    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "remainder(+5.1, 0) = " << std::remainder(5.1, 0) << '\n';
    if(fetestexcept(FE_INVALID))
        std::cout << "    FE_INVALID raised\n";
}
*/