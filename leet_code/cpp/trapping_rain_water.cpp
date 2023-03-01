#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); // n is the size of the vector
        if (n == 0) return 0; // if the vector is empty, return 0
        vector<int> left(n, 0); // create a vector of size n, and initialize all elements to 0
        vector<int> right(n, 0); // create a vector of size n, and initialize all elements to 0
        left[0] = height[0]; // left[0] is the first element of the vector
        right[n-1] = height[n-1]; // right[n-1] is the last element of the vector
        for (int i = 1; i < n; i++) { // for loop to fill the left vector
            left[i] = max(left[i-1], height[i]); // left[i] is the max of left[i-1] and height[i]
        }
        for (int i = n-2; i >= 0; i--) { // for loop to fill the right vector
            right[i] = max(right[i+1], height[i]);
        }
        int ans = 0; // initialize ans to 0
        for (int i = 0; i < n; i++) { // for loop to calculate the total water trapped
            ans += min(left[i], right[i]) - height[i]; // ans is the sum of the min of left[i] and right[i] minus height[i]
        }
        return ans; // return ans
        
    }
};

int main() {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
    return 0;
}