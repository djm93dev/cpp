#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1; // initialize two pointers to the left and right of the array
        while (left < right) { // loop until the pointers meet
            int mid = left + (right - left) / 2; // calculate the middle index
            if (nums[mid] > nums[mid + 1]) { // if the middle number is greater than the next number, move the right pointer to the middle
                right = mid; // move the right pointer to the middle
            }
            else { // if the middle number is less than the next number, move the left pointer to the middle
                left = mid + 1; // move the left pointer to the middle + 1
            }
        }
        return left; // return the left pointer

        
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}