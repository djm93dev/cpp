#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans; // create a vector to store the answer
        for (int i = 0; i < nums.size(); i++) // sort each vector in the vector
            sort(nums[i].begin(), nums[i].end());
        ans = nums[0]; // set the first vector as the answer
        for (int j = 1; j < nums.size(); j++) { // loop through the rest of the vectors
            vector<int> temp; // create a temp vector to store the intersection
            set_intersection(ans.begin(), ans.end(), nums[j].begin(), nums[j].end(), back_inserter(temp)); // find the intersection of the answer and the current vector
            ans = temp; // set the answer to the intersection
        }
        return ans; // return the answer
        
    }
};

int main() {
    vector<vector<int>> nums = { {1,2,3,4}, {2,3,4,5}, {3,4,5,6} };
    Solution sol;
    vector<int> ans = sol.intersection(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}