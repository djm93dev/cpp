#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0; // init max_len
        unordered_map<int, int> hash_map; // init hash_map
        for (int i = 0; i < nums.size(); i++) { // loop nums
            if (hash_map.find(nums[i]) == hash_map.end()) { // if not in hash_map
                int left = hash_map.find(nums[i] - 1) == hash_map.end() ? 0 : hash_map[nums[i] - 1]; // find left
                int right = hash_map.find(nums[i] + 1) == hash_map.end() ? 0 : hash_map[nums[i] + 1]; // find right
                int sum = left + right + 1; // sum
                hash_map[nums[i]] = sum; // insert into hash_map
                max_len = max(max_len, sum); // update max_len
                hash_map[nums[i] - left] = sum; // update left
                hash_map[nums[i] + right] = sum; // update right
            }
        }
        return max_len; // return max_len
        
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}