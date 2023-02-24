#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main()
{

    Solution s;
    std::vector<int> nums1 = {-1,0,0,3,3,3,0,0,0};
    std::vector<int> nums2 = {1,2,2};
    int m = nums1.size();
    int n = nums2.size();
    s.merge(nums1, m, nums2, n);
}