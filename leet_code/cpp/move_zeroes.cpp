#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0; // initialize left and right pointers
        while (right < nums.size()) {  // while right pointer is less than size of vector
            if (nums[right] != 0) { // if right pointer is not equal to 0
                swap(nums[left], nums[right]); // swap left and right pointers
                left++; // increment left pointer
            }
            right++; // increment right pointer
        }  
    }
};

int main()
{
    Solution s;
    vector<int> v = { 0, 1, 0, 3, 12 };
    s.moveZeroes(v);
    for (auto i : v)
        cout << i << " ";
}