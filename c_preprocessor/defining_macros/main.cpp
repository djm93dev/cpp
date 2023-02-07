#include <cstdio>
#include <cstdlib>
#include <ctime>

namespace bw {
    static unsigned _x = 0;
    class R {
    public:
        unsigned operator()() {
            srand(_x + (unsigned) time(0));
            return (_x += rand()) % 100;
        }
    };
}

// #define TIMES(a, b) (a * b)
// #define MAX(a, b) (a > b ? a : b)
template <typename T>
void print_max(T a, T b) {
    printf("max of %d and %d is %d\n", a, b, (a > b ? a : b));
}

int main() {
    bw::R bob;
    bw::R joe;
    print_max(bob(), joe()); // random numbers generated, but the correct max is printed
    // printf("max of %d and %d is %d\n", bob(), joe(), MAX(bob(), joe())); // random numbers generated, but the wrong max is printed
    return 0;
}