#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1; // Set the left and right pointers
        int sum = 0; // Set the sum to 0
        while (left <= right) { // While the left pointer is less than or equal to the right pointer
            sum += nums[left]; // Add the number at the left pointer to the sum
            left++; // Increment the left pointer
        }
        // create two more pointers
        int left2 = 0, right2 = nums.size() - 1;
        int sum2 = 0; // Set the sum to 0
        for (int i = 0; i < nums.size(); i++) { // Iterate through the array
            sum2 += nums[i]; // Add the number at the left pointer to the sum
            if (sum2 > sum) { // If the sum is greater than the sum
                sum = sum2; // Set the sum to the sum2
                left = left2; // Set the left pointer to the left2 pointer
                right = i; // Set the right pointer to the current index
            }
            if (sum2 < 0) { // If the sum is less than 0
                sum2 = 0; // Set the sum to 0
                left2 = i + 1; // Set the left2 pointer to the current index + 1
            }
        }
        return sum; // Return the sum

    }
};

int main() {
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = s.maxSubArray(nums);
    cout << ans << endl;
    return 0;
}