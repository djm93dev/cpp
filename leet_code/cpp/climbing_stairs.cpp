#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 1); // create a vector of size n + 1 and initialize all elements to 1
        for (int i = 2; i <= n; i++) { // iterate through the vector starting at 2
            dp[i] = dp[i - 1] + dp[i - 2]; // the number of ways to reach the current step is the sum of the number of ways to reach the step before and the number of ways to reach the step before that
        }
        return dp[n]; // return the number of ways to reach the last step
        
    }
};

int main() {
    Solution sol;
    cout << sol.climbStairs(2) << endl;
    cout << sol.climbStairs(3) << endl;
    return 0;
}