#include <iostream>
#include <vector>


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); // Get the size of the vector
        int i = 0; // Create a variable to store the current index
        for (int reach = 0; i < n && i <= reach; ++i) /// While the current index is less than the size of the vector and the current index is less than or equal to the reach
            reach = max(i + nums[i], reach); // Set the reach to the maximum of the current index plus the number at the current index and the reach
        return i == n; // Return whether the current index is equal to the size of the vector
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    bool ans = s.canJump(nums);
    cout << ans << endl;
    return 0;
}