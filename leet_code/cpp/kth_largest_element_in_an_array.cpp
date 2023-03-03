#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth; // initialize left to 0, right to nums.size() - 1, and kth to 0
        while (true) { // while true
            int idx = partition(nums, left, right); // set idx to the return value of partition(nums, left, right)
            if (idx == k - 1) { // if idx is equal to k - 1
                kth = nums[idx]; // set kth to nums[idx]
                break; // break
            }
            if (idx < k - 1) {  // if idx is less than k - 1
                left = idx + 1; // set left to idx + 1
            } else { // otherwise
                right = idx - 1; // set right to idx - 1
            }
        }
        return kth; // return kth
    }
private:
    int partition(vector<int>& nums, int left, int right) { // partition function
        int pivot = nums[left], l = left + 1, r = right; // initialize pivot to nums[left], l to left + 1, and r to right
        while (l <= r) { // while l is less than or equal to r
            if (nums[l] < pivot && nums[r] > pivot) { // if nums[l] is less than pivot and nums[r] is greater than pivot
                swap(nums[l++], nums[r--]); // swap nums[l] and nums[r] and increment l and decrement r
            }
            if (nums[l] >= pivot) { // if nums[l] is greater than or equal to pivot
                l++; // increment l
            }
            if (nums[r] <= pivot) { // if nums[r] is less than or equal to pivot
                r--; // decrement r
            }
        }
        swap(nums[left], nums[r]); // swap nums[left] and nums[r]
        return r; // return r
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << s.findKthLargest(nums, k) << endl;
    return 0;
}