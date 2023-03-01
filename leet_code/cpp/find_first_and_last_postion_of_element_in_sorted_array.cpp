#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { // this solution is O(logn) time complexity
        int left = 0, right = nums.size() - 1; // initialize left and right pointers to the first and last element of the array
        vector<int> ans; // initialize a vector to store the result
        while(left <= right){ // while left pointer is less than or equal to right pointer
            int mid = left + (right - left) / 2; // calculate the middle index
            if(nums[mid] == target){ // if the middle element is the target
                int i = mid, j = mid;  // initialize two pointers to the middle element
                while(i >= 0 && nums[i] == target) // while the left pointer is greater than or equal to 0 and the element at the left pointer is the target
                    i--; // move the left pointer to the left
                while(j < nums.size() && nums[j] == target) // while the right pointer is less than the size of the array and the element at the right pointer is the target
                    j++; // move the right pointer to the right
                ans.push_back(i + 1); // push the left pointer + 1 to the result vector
                ans.push_back(j - 1); // push the right pointer - 1 to the result vector
                return ans; // return the result vector
            }
            if(nums[mid] > target) // if the middle element is greater than the target
                right = mid - 1; // move the right pointer to the middle element - 1
            else
                left = mid + 1; // otherwise, move the left pointer to the middle element + 1
        }
        ans.push_back(-1); // if the target is not found, push -1 to the result vector
        ans.push_back(-1); // if the target is not found, push -1 to the result vector
        return ans; // return the result vector
    }
};

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution s;
    vector<int> ans = s.searchRange(nums, target);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}