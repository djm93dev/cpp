#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permuteHelper(vector<int>& nums, int left, int right, vector<vector<int>>& ans) { // helper function to find all permutations of a vector of integers
    if (left == right) { // if left is equal to right
        ans.push_back(nums); // push nums into ans
    } else {
        for (int i = left; i <= right; i++) { // for loop to swap the elements of nums
            swap(nums[left], nums[i]); // swap the elements of nums
            permuteHelper(nums, left + 1, right, ans); // call the helper function again
            swap(nums[left], nums[i]); // swap the elements of nums
        }
    }
}


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) { 
        vector<vector<int>> ans; // create a vector of vectors of integers called ans
        int left = 0, right = nums.size() - 1; // set left to 0 and right to the size of nums minus 1
        permuteHelper(nums, left, right, ans); // call the helper function
        return ans;
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = s.permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}