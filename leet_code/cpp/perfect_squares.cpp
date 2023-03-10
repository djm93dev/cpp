#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX); // set dp to a vector of size n + 1 and value INT_MAX
        dp[0] = 0; // set dp[0] to 0
        for (int i = 1; i <= n; i++) { // for i from 1 to n
            for (int j = 1; j * j <= i; j++) { // for j from 1 to i
                dp[i] = min(dp[i], dp[i - j * j] + 1); // set dp[i] to min(dp[i], dp[i - j * j] + 1)
            }
        }
        return dp[n]; // return dp[n]
        
    }
};

int main() {
    Solution s;
    int n = 12;
    cout << s.numSquares(n) << endl;
    return 0;
}