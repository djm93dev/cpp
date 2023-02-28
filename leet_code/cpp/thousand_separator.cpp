#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) return "0"; // special case
        string ans; // result
        int count = 0; // count the number of digits
        while (n > 0) { // loop until n is 0
            if (count == 3) { // if count is 3, add a dot
                ans += '.'; // add a dot
                count = 0; // reset count
            }
            ans += (n % 10) + '0'; // add the last digit
            n /= 10; // remove the last digit
            count++; // increase count
        }
        reverse(ans.begin(), ans.end()); // reverse the string
        return ans; // return the result
    }
};

int main() {
    Solution sol;
    cout << sol.thousandSeparator(987) << endl;
    cout << sol.thousandSeparator(1234) << endl;
    cout << sol.thousandSeparator(123456789) << endl;
    cout << sol.thousandSeparator(0) << endl;
    return 0;
}