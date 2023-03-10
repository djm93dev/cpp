#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size(); // set n to nums.size()
        vector<int> tmp(nums); // set tmp to a vector of ints with values from nums
        sort(tmp.begin(), tmp.end()); // sort tmp
        int i = (n - 1) / 2, j = n - 1; // set i to (n - 1) / 2 and j to n - 1
        for (int k = 0; k < n; k++) { // for each int k in 0 to n
            nums[k] = k % 2 == 0 ? tmp[i--] : tmp[j--]; // if k % 2 is equal to 0, set nums[k] to tmp[i] and decrement i, else set nums[k] to tmp[j] and decrement j
        }
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    s.wiggleSort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}