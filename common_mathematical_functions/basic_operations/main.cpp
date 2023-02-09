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


/* remquo example
#include <iostream>
#include <cmath>
#include <cfenv>
#ifndef __GNUC__
#pragma STDC FENV_ACCESS ON
#endif
 
const double pi = std::acos(-1); // or std::numbers::pi since C++20
double cos_pi_x_naive(double x) { return std::cos(pi * x); }
// the period is 2, values are (0;0.5) positive, (0.5;1.5) negative, (1.5,2) positive
double cos_pi_x_smart(double x)
{
    int quadrant;
    double rem = std::remquo(x, 1, &quadrant);
    quadrant = static_cast<unsigned>(quadrant) % 2;  // The period is 2.
    return quadrant == 0 ?  std::cos(pi * rem)
                         :- std::cos(pi * rem);
}
int main()
{
    std::cout << std::showpos
              << "naive:\n"
              << "  cos(pi * 0.25) = " << cos_pi_x_naive(0.25) << '\n'
              << "  cos(pi * 1.25) = " << cos_pi_x_naive(1.25) << '\n'
              << "  cos(pi * 2.25) = " << cos_pi_x_naive(2.25) << '\n'
              << "smart:\n"
              << "  cos(pi * 0.25) = " << cos_pi_x_smart(0.25) << '\n'
              << "  cos(pi * 1.25) = " << cos_pi_x_smart(1.25) << '\n'
              << "  cos(pi * 2.25) = " << cos_pi_x_smart(2.25) << '\n'
              << "naive:\n"
              << "  cos(pi * 1000000000000.25) = "
              << cos_pi_x_naive(1000000000000.25) << '\n'
              << "  cos(pi * 1000000000001.25) = "
              << cos_pi_x_naive(1000000000001.25) << '\n'
              << "smart:\n"
              << "  cos(pi * 1000000000000.25) = "
              << cos_pi_x_smart(1000000000000.25) << '\n'
              << "  cos(pi * 1000000000001.25) = "
              << cos_pi_x_smart(1000000000001.25) << '\n';
    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    int quo;
    std::cout << "remquo(+Inf, 1) = " << std::remquo(INFINITY, 1, &quo) << '\n';
    if(fetestexcept(FE_INVALID)) std::cout << "  FE_INVALID raised\n";
}
*/


/* fma example
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfenv>
#ifndef __GNUC__
#pragma STDC FENV_ACCESS ON
#endif
int main()
{
    // demo the difference between fma and built-in operators
    const double in = 0.1;
    std::cout << "0.1 double is " << std::setprecision(23) << in
              << " (" << std::hexfloat << in << std::defaultfloat << ")\n"
              << "0.1*10 is 1.0000000000000000555112 (0x8.0000000000002p-3), "
              << "or 1.0 if rounded to double\n";
    const double expr_result = 0.1 * 10 - 1;
    const double fma_result = std::fma(0.1, 10, -1);
    std::cout << "0.1 * 10 - 1 = " << expr_result
              << " : 1 subtracted after intermediate rounding\n"
              << "fma(0.1, 10, -1) = " << std::setprecision(6) << fma_result << " ("
              << std::hexfloat << fma_result << std::defaultfloat << ")\n\n";
 
    // fma is used in double-double arithmetic
    const double high = 0.1 * 10;
    const double low = std::fma(0.1, 10, -high);
    std::cout << "in double-double arithmetic, 0.1 * 10 is representable as "
              << high << " + " << low << "\n\n";
 
    // error handling 
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "fma(+Inf, 10, -Inf) = " << std::fma(INFINITY, 10, -INFINITY) << '\n';
    if(std::fetestexcept(FE_INVALID))
        std::cout << "    FE_INVALID raised\n";
}

*/


/* fmax example
#include <iostream>
#include <cmath>
 
int main()
{
    std::cout << "fmax(2,1)    = " << std::fmax(2,1) << '\n'
              << "fmax(-Inf,0) = " << std::fmax(-INFINITY,0) << '\n'
              << "fmax(NaN,-1) = " << std::fmax(NAN,-1) << '\n';
}
*/

/* fmin example
#include <iostream>
#include <cmath>
 
int main()
{
    std::cout << "fmin(2,1)    = " << std::fmin(2,1) << '\n'
              << "fmin(-Inf,0) = " << std::fmin(-INFINITY,0) << '\n'
              << "fmin(NaN,-1) = " << std::fmin(NAN,-1) << '\n';
}
*/

/* fdim example
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#ifndef __GNUC__
#pragma STDC FENV_ACCESS ON
#endif
int main()
{
    std::cout << "fdim(4, 1) = " << std::fdim(4, 1)
              << " fdim(1, 4) = " << std::fdim(1, 4) << '\n'
              << "fdim(4,-1) = " << std::fdim(4, -1)
              << " fdim(1,-4) = " << std::fdim(1, -4) << '\n';
    // error handling 
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "fdim(1e308, -1e308) = " << std::fdim(1e308, -1e308) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}
*/

/*nan example
#include <iostream>
#include <cmath>
#include <cstdint>
#include <cstring>
 
int main()
{
    double f1 = std::nan("1");
    std::uint64_t f1n; std::memcpy(&f1n, &f1, sizeof f1);
    std::cout << "nan(\"1\") = " << f1 << " (" << std::hex << f1n << ")\n";
 
    double f2 = std::nan("2");
    std::uint64_t f2n; std::memcpy(&f2n, &f2, sizeof f2);
    std::cout << "nan(\"2\") = " << f2 << " (" << std::hex << f2n << ")\n";
}
*/