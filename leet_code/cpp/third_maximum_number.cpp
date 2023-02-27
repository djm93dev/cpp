#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int count = 0;
        int max = nums[0];
        sort(nums.rbegin(), nums.rend()); // sort the array
        for (int i = 0; i < nums.size(); i++) { // traverse the array
            if (nums[i] != nums[i + 1]) // if the number is not equal to the next number, then increment count
                count++;
            if (count == 3) // if count is equal to 3, then return the number
                return nums[i];
        }
        return nums[0]; // return the first number
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