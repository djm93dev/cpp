#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        // case for a == 0, b == 0 or negative
        if (a == 0) { // if a is 0
            return b; // return b
        }
        if (b == 0) { // if b is 0
            return a; // return a
        }
        if (a < 0 && b < 0) { // if a and b are both negative
            return -getSum(-a, -b); // return the negative of the sum of the absolute values of a and b
        }
        // case for a == 0, b == 0 or negative 
        if (a < 0) { // if a is negative
            return b - (-a); // return b minus the absolute value of a
        }
        if (b < 0) { // if b is negative
            return a - (-b); // return a minus the absolute value of b
        }
        // case for a == 0, b == 0 or negative
        int sum = 0; // sum of a and b
        int carry = 0; // carry
        for (int i = 0; i < 32; i++) { // for each bit in a and b
            int a_bit = (a >> i) & 1; // get the i-th bit of a
            int b_bit = (b >> i) & 1; // get the i-th bit of b
            int sum_bit = a_bit ^ b_bit ^ carry; // sum of the i-th bit of a and b
            carry = (a_bit & b_bit) | (a_bit & carry) | (b_bit & carry); // carry of the i-th bit of a and b
            sum |= (sum_bit << i); // update the i-th bit of sum
        }
        return sum; // return sum
    }
};

int main() {
    Solution s;
    int a = 1, b = 2;
    cout << s.getSum(a, b) << endl;
    return 0;
}