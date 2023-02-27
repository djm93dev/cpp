#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) // loop through the vector
        {
            int count = 0; // count the number of times the number appears
            for (int j = 0; j < nums.size(); j++) // loop through the vector again
            {
                if (nums[i] == nums[j]) // if the number is the same as the number we are checking
                {
                    count++; // increment the count
                }
            }
            if (count == 1) // if the number only appears once
            {
                ans += nums[i]; // add it to the answer
            }
        }

        return ans; // return the answer

    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 2};
    cout << s.sumOfUnique(nums) << endl;
    return 0;
}