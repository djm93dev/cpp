#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            ans.push_back(accumulate(nums.begin(), nums.begin() + i + 1, 0)); // 0 is the initial value
        return ans;
            
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3, 4 };
    vector<int> result = s.runningSum(nums);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;

}