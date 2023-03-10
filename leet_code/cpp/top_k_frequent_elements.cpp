#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // key: number, value: frequency
        for (auto i : nums) { // for each number in nums
            freq[i]++; // update frequency
        }
        vector<vector<int>> buckets(nums.size() + 1); // buckets[i] contains all numbers with frequency i
        for (auto i : freq) { // for each number and its frequency
            buckets[i.second].push_back(i.first); // put the number into the bucket
        }
        vector<int> res; // result
        for (int i = buckets.size() - 1; i >= 0; i--) { // for each bucket
            for (auto j : buckets[i]) { // for each number in the bucket
                res.push_back(j); // add the number to the result
                if (res.size() == k) { // if we have k numbers
                    return res; // return the result
                }
            }
        }
        return res; // return the result
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = s.topKFrequent(nums, k);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}