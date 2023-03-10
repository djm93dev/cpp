#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(); // size of the arrays
        int count = 0; // number of quadruplets
        vector<int> sums1(n * n); // sums of the first two arrays
        vector<int> sums2(n * n); // sums of the last two arrays
        int k = 0; // index
        for (int i = 0; i < n; i++) { // for each element in nums1
            for (int j = 0; j < n; j++) { // for each element in nums2
                sums1[k] = nums1[i] + nums2[j]; // update sums1
                sums2[k] = nums3[i] + nums4[j]; // update sums2
                k++; // increase index
            }
        }
        sort(sums1.begin(), sums1.end()); // sort sums1
        sort(sums2.begin(), sums2.end()); // sort sums2
        int i = 0; // index
        int j = n * n - 1; // index
        while (i < n * n && j >= 0) { // while i is less than n * n and j is greater than or equal to 0
            if (sums1[i] + sums2[j] == 0) { // if the sum of the two elements is equal to 0
                int count1 = 1; // number of elements equal to sums1[i]
                int count2 = 1; // number of elements equal to sums2[j]
                i++; // increase i
                j--; // decrease j
                while (i < n * n && sums1[i] == sums1[i - 1]) { // while i is less than n * n and the element is equal to the previous element
                    count1++; // increase count1
                    i++; // increase i
                }
                while (j >= 0 && sums2[j] == sums2[j + 1]) { // while j is greater than or equal to 0 and the element is equal to the next element
                    count2++; // increase count2
                    j--; // decrease j
                }
                count += count1 * count2; // update count
            } else if (sums1[i] + sums2[j] < 0) { // if the sum of the two elements is less than 0
                i++; // increase i
            } else { // if the sum of the two elements is greater than 0
                j--; // decrease j
            }

        }
        return count; // return count

        
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    cout << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}