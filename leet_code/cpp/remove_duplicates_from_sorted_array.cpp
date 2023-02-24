#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    auto last = std::unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());
    int k = nums.size();
    return k;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}