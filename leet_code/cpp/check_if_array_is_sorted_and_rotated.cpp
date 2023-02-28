#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(); // number of elements in the array
        int count = 0; // number of times the array is rotated
        for (int i = 0; i < n; i++) { // loop through the array
            if (nums[i] > nums[(i + 1) % n]) { // if the current element is greater than the next element
                count++; // increment the count
            }
        }
        return count <= 1; // if the array is rotated less than or equal to 1 time, then it is sorted and rotated
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3,4,5,1,2};
    vector<int> nums2 = {2,1,3,4};
    vector<int> nums3 = {1,2,3};
    vector<int> nums4 = {1,1,1};
    vector<int> nums5 = {2,1};
    cout << sol.check(nums1) << endl;
    cout << sol.check(nums2) << endl;
    cout << sol.check(nums3) << endl;
    cout << sol.check(nums4) << endl;
    cout << sol.check(nums5) << endl;
    return 0;
}

