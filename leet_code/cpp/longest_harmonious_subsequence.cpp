#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            if (map.find(it->first + 1) != map.end()) {
                if (it->second + map[it->first + 1] > max) {
                    max = it->second + map[it->first + 1];
                }
            }
        }
        return max;
    }

};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << s.findLHS(nums) << endl;
    return 0;
}