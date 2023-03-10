#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1); // set result to a vector of size nums.size() and value 1
        int left = 1; // set left to 1
        int right = 1; // set right to 1
        for (int i = 0; i < nums.size(); i++) { // for i from 0 to nums.size()
            result[i] *= left; // set result[i] to result[i] * left
            left *= nums[i]; // set left to left * nums[i]
            result[nums.size() - 1 - i] *= right; // set result[nums.size() - 1 - i] to result[nums.size() - 1 - i] * right
            right *= nums[nums.size() - 1 - i]; // set right to right * nums[nums.size() - 1 - i]
        }
        return result; // return result
        
    }
};

int main() {
    Solution s;
    return 0;
}