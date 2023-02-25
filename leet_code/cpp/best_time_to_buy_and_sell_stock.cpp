#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = prices[0], profit = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > buy) profit = max(prices[i]-buy, profit);
            else buy = prices[i];
        }
        return profit;
    }
};

int main(){
    vector<int> prices = {2,4,1};
    Solution sol;
    int profit = sol.maxProfit(prices);
    cout << "Profit: " << profit << endl;
    return 0;
}