#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(); // m is the size of the string s
        int n = p.size(); // n is the size of the string p
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false)); // create a 2D vector of size m+1 by n+1, and initialize all elements to false
        dp[0][0] = true; // dp[0][0] is true
        for (int i = 1; i <= n; i++) { // for loop to fill the first row of the 2D vector
            if (p[i-1] == '*') { // if the character at index i-1 of p is a *
                dp[0][i] = dp[0][i-1]; // dp[0][i] is the same as dp[0][i-1]
            }
        }
        for (int i = 1; i <= m; i++) { // for loop to fill the first column of the 2D vector
            for (int j = 1; j <= n; j++) { // for loop to fill the rest of the 2D vector
                if (p[j-1] == '*') { // if the character at index j-1 of p is a *
                    dp[i][j] = dp[i-1][j] || dp[i][j-1]; // dp[i][j] is the same as dp[i-1][j] or dp[i][j-1]
                } else if (p[j-1] == '?' || s[i-1] == p[j-1]) { // if the character at index j-1 of p is a ? or the character at index i-1 of s is the same as the character at index j-1 of p
                    dp[i][j] = dp[i-1][j-1]; // dp[i][j] is the same as dp[i-1][j-1]
                }
            }
        }
        return dp[m][n]; // return dp[m][n]

        
    }
};

int main() {
    Solution s;
    string s1 = "aa";
    string p1 = "a";
    cout << s.isMatch(s1, p1) << endl;
    return 0;
}