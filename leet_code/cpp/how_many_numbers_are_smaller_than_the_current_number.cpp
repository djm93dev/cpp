#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] > nums[j])
                    count++;
            }
            ans.push_back(count);
            count = 0;
        }
        return ans;

        
    }
};

int main() {
    Solution s;
    vector<int> nums = { 8,1,2,2,3 };
    vector<int> ans = s.smallerNumbersThanCurrent(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}