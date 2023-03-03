#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-'; // if the numerator is negative and the denominator is positive or vice versa, add a negative sign to the result
        long n = labs(numerator), d = labs(denominator), r = n % d; // get the absolute value of the numerator and denominator and the remainder of the numerator and denominator
        res += to_string(n / d); // add the quotient of the numerator and denominator to the result
        if (r == 0) return res; // if the remainder is 0, return the result
        res += '.'; // add a decimal point to the result
        unordered_map<int, int> m; // create a map to store the remainder and the index of the result
        while (r) {
            if (m.count(r) > 0) { // if the remainder is in the map
                res.insert(m[r], 1, '('); // insert a parenthesis at the index of the remainder
                res += ')'; // add a closing parenthesis to the result
                break; // break out of the loop
            }
            m[r] = res.size(); // add the remainder and the index of the result to the map
            r *= 10; // multiply the remainder by 10
            res += to_string(r / d); // add the quotient of the remainder and denominator to the result
            r %= d; // get the remainder of the remainder and denominator
        }
        return res; // return the result
        
    }
};

int main()
{
    Solution s;
    cout << s.fractionToDecimal(1, 2) << endl;
    return 0;
}