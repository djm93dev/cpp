#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0; // set the left pointer
        int right = 1; // set the right pointer
        int profit = 0; // set the profit to 0
        while (right < prices.size()) { // while the right pointer is less than the size of the vector
            if (prices[left] < prices[right]) { // if the left pointer is less than the right pointer
                profit += prices[right] - prices[left]; // add the difference to the profit
            }
            left++; // increment the left pointer
            right++; // increment the right pointer
        }
        return profit; // return the profit
        
    }
};

int main() {
    Solution s;
    return 0;
}