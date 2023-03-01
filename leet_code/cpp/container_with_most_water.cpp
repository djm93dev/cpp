#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1; // the left pointer is at the beginning of the vector and the right pointer is at the end of the vector
        int ans = 0; // the answer
        while (left < right) { // while the left pointer is less than the right pointer
            int area = min(height[left], height[right]) * (right - left); // calculate the area of the container by multiplying the minimum of the height of the left pointer and the height of the right pointer by the difference between the right pointer and the left pointer
            ans = max(ans, area); // set ans to the max of ans and area 
            if (height[left] < height[right]) { // if the height of the left pointer is less than the height of the right pointer
                left++; // move the left pointer to the right
            } else { // if the height of the left pointer is greater than or equal to the height of the right pointer
                right--; // move the right pointer to the left 
            }
        }
        return ans; // return ans
        
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    int ans = sol.maxArea(height);
    cout << ans;
    return 0;
}