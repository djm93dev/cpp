#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string_view>
 
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long int y = 0;
        int z = x;
        while (z > 0) {
            y = y * 10 + z % 10;
            z /= 10;
        }
        if (y == x) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << boolalpha << s.isPalindrome(121) << endl;
    cout << boolalpha << s.isPalindrome(-121) << endl;
    cout << boolalpha << s.isPalindrome(10) << endl;
    return 0;
}