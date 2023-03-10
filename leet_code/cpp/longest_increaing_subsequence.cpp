#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0; // if nums.size() is equal to 0 return 0
        vector<int> dp(nums.size(), 1); // create a vector of ints dp and set it to nums.size() and 1
        int res = 1; // create an int res and set it to 1
        for (int i = 1; i < nums.size(); i++) { // for each int i in nums.size()
            for (int j = 0; j < i; j++) { // for each int j in i
                if (nums[i] > nums[j]) { // if nums[i] is greater than nums[j]
                    dp[i] = max(dp[i], dp[j] + 1); // set dp[i] to max(dp[i], dp[j] + 1)
                }
            }
            res = max(res, dp[i]); // set res to max(res, dp[i])
        }
        return res; // return res
    }
};

int main() {
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}