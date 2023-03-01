#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left, right, sum; // initialize three pointers
        vector<vector<int>> ans; // initialize the answer
        sort(nums.begin(), nums.end()); // sort the array
        for (int i = 0; i < nums.size(); i++) { // loop through the array
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip the same number
            left = i + 1; // left pointer starts from the next number
            right = nums.size() - 1; // right pointer starts from the last number
            while (left < right) {  // loop until left and right pointers meet
                sum = nums[i] + nums[left] + nums[right]; // calculate the sum
                if (sum == 0) { // if the sum is 0, add the triplet to the answer
                    ans.push_back({nums[i], nums[left], nums[right]}); // add the triplet to the answer
                    while (left < right && nums[left] == nums[left + 1]) left++; // skip the same number
                    while (left < right && nums[right] == nums[right - 1]) right--; // skip the same number
                    left++; // move the pointers
                    right--; // move the pointers
                }
                else if (sum < 0) left++; // if the sum is less than 0, move the left pointer to the right
                else right--; // if the sum is greater than 0, move the right pointer to the left
            }
        }
        return ans; // return the answer

        
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = s.threeSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;

}