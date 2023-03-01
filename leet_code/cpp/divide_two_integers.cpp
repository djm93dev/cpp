#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX; // if divisor is 0, return INT_MAX
        if (dividend == 0) return 0; // if dividend is 0, return 0
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // if dividend is INT_MIN and divisor is -1, return INT_MAX
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; // if dividend and divisor have different signs, sign is -1, otherwise sign is 1
        long long dvd = labs(dividend); // convert dividend to long long
        long long dvs = labs(divisor); // convert divisor to long long
        int res = 0; // initialize res
        while (dvd >= dvs) { // while dvd is greater than or equal to dvs
            long long temp = dvs, multiple = 1; // initialize temp and multiple
            while (dvd >= (temp << 1)) { // while dvd is greater than or equal to temp * 2
                temp <<= 1; // temp * 2
                multiple <<= 1; // multiple * 2
            }
            dvd -= temp; // dvd - temp
            res += multiple; // res + multiple
        }
        return sign == 1 ? res : -res; // if sign is 1, return res, otherwise return -res
        
    }
};

int main()
{
    Solution s;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(7, -3) << endl;
    return 0;
}