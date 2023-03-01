#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversed_number = 0, remainder; // initialize reversed_number and remainder
        while (x != 0) {  // while x is not 0
            remainder = x % 10; // remainder is the last digit of x
            if (reversed_number > INT_MAX / 10 || (reversed_number == INT_MAX / 10 && remainder > 7)) return 0; // if reversed_number is greater than INT_MAX / 10 or if reversed_number is equal to INT_MAX / 10 and remainder is greater than 7, return 0
            if (reversed_number < INT_MIN / 10 || (reversed_number == INT_MIN / 10 && remainder < -8)) return 0; // if reversed_number is less than INT_MIN / 10 or if reversed_number is equal to INT_MIN / 10 and remainder is less than -8, return 0
            reversed_number = reversed_number * 10 + remainder; // reversed_number is reversed_number * 10 + remainder
            x /= 10; // x is x / 10
        }
        return reversed_number; // return reversed_number
        
    }
};

int main() {
    int x = 123;
    Solution s;
    int ans = s.reverse(x);
    cout << ans;
    return 0;
}