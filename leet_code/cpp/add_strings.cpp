#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result = "";
        while (i >= 0 || j >= 0 || carry == 1)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                sum += num2[j] - '0';
                j--;
            }
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }
        return result;
    }
};

int main ()
{
    Solution s;
    std::cout << s.addStrings("11", "123") << std::endl;
    std::cout << s.addStrings("456", "77") << std::endl;
    std::cout << s.addStrings("0", "0") << std::endl;
    return 0;

}