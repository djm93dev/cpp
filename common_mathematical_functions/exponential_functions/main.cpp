/*exp example
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "exp(1) = e¹ = " << std::setprecision(16) << std::exp(1) << '\n'
              << "FV of $100, continuously compounded at 3% for 1 year = "
              << std::setprecision(6) << 100*std::exp(0.03) << '\n';
    // special values
    std::cout << "exp(-0) = " << std::exp(-0.0) << '\n'
              << "exp(-Inf) = " << std::exp(-INFINITY) << '\n';
    // error handling 
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "exp(710) = " << std::exp(710) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}
*/

/* exp2 example
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "exp2(4) = " << std::exp2(4) << '\n'
              << "exp2(0.5) = " << std::exp2(0.5) << '\n'
              << "exp2(-4) = " << std::exp2(-4) << '\n';
    // special values
    std::cout << "exp2(-0) = " << std::exp2(-0.0) << '\n'
              << "exp2(-Inf) = " << std::exp2(-INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "exp2(1024) = " << std::exp2(1024) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}
*/

/* expml example - returns e^x - 1
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "expm1(1) = " << std::expm1(1) << '\n'
              << "Interest earned in 2 days on on $100, compounded daily at 1%\n"
              << " on a 30/360 calendar = "
              << 100*std::expm1(2*std::log1p(0.01/360)) << '\n'
              << "exp(1e-16)-1 = " << std::exp(1e-16)-1
              << ", but expm1(1e-16) = " << std::expm1(1e-16) << '\n';
    // special values
    std::cout << "expm1(-0) = " << std::expm1(-0.0) << '\n'
              << "expm1(-Inf) = " << std::expm1(-INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "expm1(710) = " << std::expm1(710) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_OVERFLOW))
        std::cout << "    FE_OVERFLOW raised\n";
}
*/

/* log example computes natural (base e) logarithm (lnx)
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "log(1) = " << std::log(1) << '\n'
              << "base-5 logarithm of 125 = " << std::log(125)/std::log(5) << '\n';
    // special values
    std::cout << "log(1) = " << std::log(1) << '\n'
              << "log(+Inf) = " << std::log(INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "log(0) = " << std::log(0) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_DIVBYZERO))
        std::cout << "    FE_DIVBYZERO raised\n";
}
*/

/* log10 example computes base-10 logarithm (log10x)
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "log10(1000) = " << std::log10(1000) << '\n'
              << "log10(0.001) = " << std::log10(0.001) << '\n'
              << "base-5 logarithm of 125 = " << std::log10(125)/std::log10(5) << '\n';
    // special values
    std::cout << "log10(1) = " << std::log10(1) << '\n'
              << "log10(+Inf) = " << std::log10(INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "log10(0) = " << std::log10(0) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_DIVBYZERO))
        std::cout << "    FE_DIVBYZERO raised\n";
}
*/

/*log2 example computes base-2 logarithm (log2x)
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "log2(65536) = " << std::log2(65536) << '\n'
              << "log2(0.125) = " << std::log2(0.125) << '\n'
              << "log2(0x020f) = " << std::log2(0x020f)
              << " (highest set bit is in position 9)\n"
              << "base-5 logarithm of 125 = " << std::log2(125)/std::log2(5) << '\n';
    // special values
    std::cout << "log2(1) = " << std::log2(1) << '\n'
              << "log2(+Inf) = " << std::log2(INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "log2(0) = " << std::log2(0) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_DIVBYZERO))
        std::cout << "    FE_DIVBYZERO raised\n";
}
*/

/* log1p example computes natural (base e) logarithm of 1+x (ln(1+x))
#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>
// #pragma STDC FENV_ACCESS ON
int main()
{
    std::cout << "log1p(0) = " << log1p(0) << '\n'
              << "Interest earned in 2 days on on $100, compounded daily at 1%\n"
              << " on a 30/360 calendar = "
              << 100*expm1(2*log1p(0.01/360)) << '\n'
              << "log(1+1e-16) = " << std::log(1+1e-16)
              << " log1p(1e-16) = " << std::log1p(1e-16) << '\n';
    // special values
    std::cout << "log1p(-0) = " << std::log1p(-0.0) << '\n'
              << "log1p(+Inf) = " << std::log1p(INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "log1p(-1) = " << std::log1p(-1) << '\n';
    if (errno == ERANGE)
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    if (std::fetestexcept(FE_DIVBYZERO))
        std::cout << "    FE_DIVBYZERO raised\n";
}
*/