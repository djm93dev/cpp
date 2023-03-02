#include <iostream>
#include <vector>

using namespace std;

void subsetsHelper(vector<int>& nums, vector<int>& out, vector<vector<int>>& res, int pos) { // helper function
    res.push_back(out); // push the current vector into the result vector
    for (int i = pos; i < nums.size(); i++) { // iterate through the vector
        out.push_back(nums[i]); // push the current element into the output vector
        subsetsHelper(nums, out, res, i + 1); // call the helper function with the current position incremented by 1
        out.pop_back(); // pop the last element from the output vector
    }
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { // main function
        vector<vector<int>> res; // create a vector of vectors
        vector<int> out; // create a vector
        subsetsHelper(nums, out, res, 0); // call the helper function
        return res; // return the result vector
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.subsets(nums);
    return 0;
}