#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0; // index
        int sign = 1; // sign
        int ans = 0; // answer
        while (s[i] == ' ') { // skip white space
            i++; // increment index 
        }
        if (s[i] == '-') { // check for sign
            sign = -1; // set sign to negative
            i++; // increment index
        } else if (s[i] == '+') { // check for sign
            i++; // increment index
        }
        while (s[i] >= '0' && s[i] <= '9') { // while s[i] is a digit
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > 7)) { // if ans is greater than INT_MAX / 10 or if ans is equal to INT_MAX / 10 and s[i] - '0' is greater than 7, return INT_MAX or INT_MIN
                return sign == 1 ? INT_MAX : INT_MIN; // return INT_MAX or INT_MIN
            }
            ans = ans * 10 + (s[i] - '0'); // ans is ans * 10 + s[i] - '0'
            i++; // increment index
        }
        return ans * sign; // return ans * sign
        
    }
};

int main() {
    string s = "42";
    Solution sol;
    int ans = sol.myAtoi(s);
    cout << ans;
    return 0;
}