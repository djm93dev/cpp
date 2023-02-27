#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans; // create vector to store indices of target
        sort(nums.begin(), nums.end()); // sort nums
        for (int i = 0; i < nums.size(); i++) // for each element in nums
            if (nums[i] == target) // if element is equal to target
                ans.push_back(i); // add index of element to ans
        return ans; // return ans
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,5,2,3};
    int target = 2;
    vector<int> ans = s.targetIndices(nums, target);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}