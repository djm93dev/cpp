#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(); // get the size of the string
        vector<int> dp(n + 1); // create a vector to store the number of ways to decode the string
        dp[0] = 1; // if the string is empty, there is only one way to decode it
        for (int i = 1; i <= n; ++i) { // traverse the string
            if (s[i - 1] != '0') { // if the current character is not 0
                dp[i] += dp[i - 1]; // add the number of ways to decode the string without the current character to the number of ways to decode the string
            }
            if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26) { // if the current character and the previous character can be decoded as a letter
                dp[i] += dp[i - 2]; // add the number of ways to decode the string without the current character and the previous character to the number of ways to decode the string
            }
        }
        return dp[n]; // return the number of ways to decode the string
        
    }
};

int main() {
    Solution s;
    string s = "12";
    std::cout << s.numDecodings(s) << std::endl;
    return 0;
}