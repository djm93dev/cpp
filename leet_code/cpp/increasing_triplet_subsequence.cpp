#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX; // first and second smallest numbers
        for (int n : nums) { // for each number in nums
            if (n <= first) { // if n is smaller than first, update first
                first = n; // update first
            } else if (n <= second) { // if n is smaller than second, update second
                second = n; // update second
            } else {
                return true; // if n is larger than both, return true
            }
        }
        return false; // if we get here, there is no increasing triplet
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.increasingTriplet(nums) << endl;
    return 0;
}