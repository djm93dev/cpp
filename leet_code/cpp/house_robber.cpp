#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); // set n to the size of the vector
        if (n == 0) return 0; // if the vector is empty return 0
        if (n == 1) return nums[0]; // if the vector has one element return that element
        if (n == 2) return max(nums[0], nums[1]); // if the vector has two elements return the max of the two
        vector<int> dp(n, 0); // create a vector of size n and initialize all elements to 0
        dp[0] = nums[0]; // set the first element to the first element of the vector
        dp[1] = max(nums[0], nums[1]); // set the second element to the max of the first two elements of the vector
        for (int i = 2; i < n; i++) { // loop through the vector starting at the third element
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); // set the current element to the max of the previous element and the element two elements before the current element plus the current element
        }
        return dp[n - 1]; // return the last element of the vector
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.rob(nums) << endl;
    return 0;
}