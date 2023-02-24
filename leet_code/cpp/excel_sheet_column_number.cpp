#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle)
        {
			//d = s[i](char) - 'A' + 1 (we used  s[i] -  'A' to convert the letter to a number like it's going to be C)
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};

int main ()
{
    Solution s;
    std::cout << s.titleToNumber("A") << std::endl; // 1
    std::cout << s.titleToNumber("AB") << std::endl; // 28 = 26^0 + 2^0
    std::cout << s.titleToNumber("ZY") << std::endl; // 701 = 26^1 + 25^0
    std::cout << s.titleToNumber("FXSHRXW") << std::endl; // 2147483647
    return 0;

}