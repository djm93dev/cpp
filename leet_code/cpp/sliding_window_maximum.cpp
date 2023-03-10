#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; // set result to a vector of ints
        if (nums.size() == 0) { // if nums.size() is 0
            return result; // return result
        }
        deque<int> dq; // set dq to a deque of ints
        for (int i = 0; i < k; i++) { // for i from 0 to k
            while (!dq.empty() && nums[i] >= nums[dq.back()]) { // while dq is not empty and nums[i] is greater than or equal to nums[dq.back()]
                dq.pop_back(); // pop dq.back()
            }
            dq.push_back(i); // push i to dq
        }
        for (int i = k; i < nums.size(); i++) { // for i from k to nums.size()
            result.push_back(nums[dq.front()]); // push nums[dq.front()] to result
            while (!dq.empty() && dq.front() <= i - k) { // while dq is not empty and dq.front() is less than or equal to i - k
                dq.pop_front(); // pop dq.front()
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) { // while dq is not empty and nums[i] is greater than or equal to nums[dq.back()]
                dq.pop_back(); // pop dq.back()
            }
            dq.push_back(i); // push i to dq
        }
        result.push_back(nums[dq.front()]); // push nums[dq.front()] to result
        return result; // return result
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = s.maxSlidingWindow(nums, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}