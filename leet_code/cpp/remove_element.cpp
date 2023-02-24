#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    
    auto rm = std::remove(nums.begin(), nums.end(), val);
    nums.erase(rm, nums.end());
    int ans = nums.size();

    cout << "ans: " << ans << endl;
    return ans;
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int ans = s.removeElement(nums, val);
    
    return 0;
}