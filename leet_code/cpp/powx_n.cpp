#include <iostream>


using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // convert n to long long
        long long N = n; // N is the power
        if (N < 0) { // If the power is negative
            x = 1 / x; // Invert the number
            N = -N; // Make the power positive
        }
        // calculate the power
        double ans = 1; // Set the answer to 1
        double current_product = x; // Set the current product to x
        for (long long i = N; i; i /= 2) { // Iterate through the power
            if (i % 2 == 1) { // If the power is odd
                ans = ans * current_product; // Multiply the answer by the current product
            }
            current_product = current_product * current_product; // Square the current product
        }
        return ans; // Return the answer
        
    }
};

int main() {
    Solution s;
    double x = 2.00000;
    int n = 10;
    double ans = s.myPow(x, n);
    cout << ans << endl;
    return 0;
}