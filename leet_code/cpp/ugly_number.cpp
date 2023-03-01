#include <iostream>

using namespace std;

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false; // 0 is not ugly number
        if (n == 1) return true; // 1 is ugly number
        if (n % 2 == 0) return isUgly(n / 2); // if n is even, divide by 2
        if (n % 3 == 0) return isUgly(n / 3); // if n is divisible by 3, divide by 3
        if (n % 5 == 0) return isUgly(n / 5); // if n is divisible by 5, divide by 5
        return false;
    }

};

int main()
{
    Solution s;
    s.isUgly(14);
}