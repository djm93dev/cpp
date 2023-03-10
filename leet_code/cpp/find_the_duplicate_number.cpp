#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1; // set left to 1
        int right = nums.size() - 1; // set right to nums.size() - 1
        while (left < right) { // while left is less than right
            int mid = left + (right - left) / 2; // set mid to left + (right - left) / 2
            int count = 0; // set count to 0
            for (int i = 0; i < nums.size(); i++) { // for i from 0 to nums.size()
                if (nums[i] <= mid) { // if nums[i] is less than or equal to mid
                    count++; // increment count
                }
            }
            if (count <= mid) { // if count is less than or equal to mid
                left = mid + 1; // set left to mid + 1
            } else { // else
                right = mid; // set right to mid
            }
        }
        return left; // return left
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 4, 2, 2};
    int result = s.findDuplicate(nums);
    cout << result << endl;
    return 0;
}