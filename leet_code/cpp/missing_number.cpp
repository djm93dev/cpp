#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort the array
        int i = 0; // index
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i) { // if the number is not equal to the index
                return i; // return the index
            }
        }
        return i; // if the number is equal to the index, return the index
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,1,3};
    cout << s.missingNumber(nums) << endl;
    return 0;
}