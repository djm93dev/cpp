#include <iostream>


using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // convert n to long long
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        // calculate the power
        double ans = 1;
        double current_product = x;
        for (long long i = N; i; i /= 2) {
            if (i % 2 == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
        
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