#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend()); // sort the array
        int count = 0;
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != max) {
                count++;
                max = nums[i];
            }
            if (count == 2)
                return max;
        }
        return nums[0];
    }
};


int main()
{
    vector<int> nums = {1,2,2,5,3,5,6,7};
    Solution sol;
    int ans = sol.thirdMax(nums);
    cout << ans << endl;
    return 0;
}