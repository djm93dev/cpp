#include <iostream>
#include <vector>

using namespace std;

// class Solution { // this solution is not good enough, it is O(n) time complexity, but it is easy to understand and implement we can use binary search to improve the time complexity to O(logn)
// public:
//     int search(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++)
//             if(nums[i] == target)
//                 return i;
//         return -1;
        
//     }
// };

class Solution { // this solution is O(logn) time complexity
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; // initialize left and right pointers to the first and last element of the array
        while(left <= right){  // while left pointer is less than or equal to right pointer
            int mid = left + (right - left) / 2;  // calculate the middle index
            if(nums[mid] == target)  // if the middle element is the target, return the index
                return mid;  
            if(nums[mid] >= nums[left]){  // if the middle element is greater than or equal to the left element, then the left half of the array is sorted
                if(target >= nums[left] && target < nums[mid])  // if the target is greater than or equal to the left element and less than the middle element, then the target is in the left half of the array
                    right = mid - 1; // move the right pointer to the middle element - 1
                else 
                    left = mid + 1; // otherwise, move the left pointer to the middle element + 1
            }
            else{
                if(target > nums[mid] && target <= nums[right]) // if the target is greater than the middle element and less than or equal to the right element, then the target is in the right half of the array
                    left = mid + 1; // move the left pointer to the middle element + 1
                else
                    right = mid - 1; // otherwise, move the right pointer to the middle element - 1
            }
        }
        return -1; // if the target is not found, return -1
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << s.search(nums, 0) << endl;
    return 0;
}