#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1; // left and right pointers
        for (int i = 0; i <= right; i++) { // iterate through the vector
            if (nums[i] == 0) { // if the current element is 0
                swap(nums[i], nums[left]); // swap the current element with the element at the left pointer
                left++; // increment the left pointer
            }
            else if (nums[i] == 2) { // if the current element is 2
                swap(nums[i], nums[right]); // swap the current element with the element at the right pointer
                right--; // decrement the right pointer
                i--; // decrement the current index
            }
        }

    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for (auto i : nums)
        cout << i << " ";
    return 0;
}