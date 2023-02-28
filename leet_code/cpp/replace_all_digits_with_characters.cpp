#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        // for each odd index
        for(int i = 1; i < s.size(); i+=2) // for each odd index
            s[i] = s[i-1] + s[i] - '0'; // add the previous character to the current character
        return s; // return the string

 
    }
};

int main()
{
    Solution s;
    string str = "a1c1e1";
    std::cout << s.replaceDigits(str) << std::endl;
    return 0;
}