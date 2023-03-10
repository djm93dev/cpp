#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) { // if n is 0
            return false; // return false
        }
        while (n % 3 == 0) { // while n is divisible by 3
            n /= 3; // divide n by 3
        }
        return n == 1; // return true if n is 1, otherwise return false
        
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfThree(27) << endl;
    cout << s.isPowerOfThree(0) << endl;
    cout << s.isPowerOfThree(9) << endl;
    cout << s.isPowerOfThree(45) << endl;
    return 0;
}