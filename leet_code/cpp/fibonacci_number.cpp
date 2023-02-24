#include <numeric>
#include <vector>
#include <array>
#include <iostream>
#include <functional>
#include <iterator>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }
};
int main () {
    Solution sol;
    int n = 21;
    int result = sol.fib(n);
    cout << "Fibonacci number of " << n << " is " << result << endl;
    return 0;
}

