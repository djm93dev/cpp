#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end()); // sort the array
        int i = 1; // the smallest number is 1
        for (int j = 0; j < nums.size(); j++) { // traverse the array
            if (nums[j] == i) { // if the number is equal to i, then i++
                i++;  // increment i
                continue;
            }
            else if (nums[j] > i) { // if the number is greater than i, then push i into the ans array
                while (nums[j] > i) { // if the number is greater than i, then push i into the ans array
                    ans.push_back(i); // push i into the ans array
                    i++; // increment i
                }
                i++; // increment i
            }
        }
        while (i <= nums.size()) { // if i is less than or equal to the size of the array, then push i into the ans array
            ans.push_back(i); // push i into the ans array
            i++; // increment i
        }
        return ans;

        
    }
};

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution sol;
    vector<int> ans = sol.findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}