#include <iostream>
#include <vector>


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return i == n;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    bool ans = s.canJump(nums);
    cout << ans << endl;
    return 0;
}