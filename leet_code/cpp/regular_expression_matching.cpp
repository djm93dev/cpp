#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(); // length of s
        int n = p.size(); // length of p
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false)); // dp table
        dp[0][0] = true; // if s and p are empty, return true
        for (int i = 1; i <= n; i++) { // if s is empty and p is not empty
            if (p[i - 1] == '*') { // if p[i - 1] is a *
                dp[0][i] = dp[0][i - 2]; // set dp[0][i] to dp[0][i - 2]
            }
        }
        for (int i = 1; i <= m; i++) { // for each character in s
            for (int j = 1; j <= n; j++) { // for each character in p
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) { // if p[j - 1] is a . or if p[j - 1] is equal to s[i - 1]
                    dp[i][j] = dp[i - 1][j - 1]; // set dp[i][j] to dp[i - 1][j - 1]
                } else if (p[j - 1] == '*') { // if p[j - 1] is a *
                    dp[i][j] = dp[i][j - 2]; // set dp[i][j] to dp[i][j - 2]
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) { // if p[j - 2] is a . or if p[j - 2] is equal to s[i - 1]
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // set dp[i][j] to dp[i][j] or dp[i - 1][j]
                    }
                } else {
                    dp[i][j] = false; // set dp[i][j] to false
                }
            }
        }
        return dp[m][n]; // return dp[m][n]
        
    }
};

int main() {
    string s = "aa";
    string p = "a";
    Solution sol;
    bool ans = sol.isMatch(s, p);
    cout << ans;
    return 0;
}