#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1); // set dp to a vector of ints with size amount+1 and all values set to amount+1
        dp[0] = 0; // set dp[0] to 0
        for (int i = 1; i <= amount; i++) { // for each int i in 1 to amount
            for (int j = 0; j < coins.size(); j++) { // for each int j in 0 to coins.size()
                if (coins[j] <= i) { // if coins[j] is less than or equal to i
                    dp[i] = min(dp[i], dp[i-coins[j]]+1); // set dp[i] to min(dp[i], dp[i-coins[j]]+1)
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; // return dp[amount] if dp[amount] is less than or equal to amount, otherwise return -1
        
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << s.coinChange(coins, amount) << endl;
    return 0;
}