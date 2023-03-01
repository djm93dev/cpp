#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums2.size(); i++) // loop through nums2
            nums1.push_back(nums2[i]); // push nums2 to nums1
        sort(nums1.begin(), nums1.end()); // sort nums1
        if (nums1.size() % 2 == 0) // if nums1 is even
            return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0; // return the average of the two middle numbers
        else 
            return nums1[nums1.size() / 2]; // return the middle number
        
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    Solution s;
    double ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans;
    return 0;
}