#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0]; // Create a variable to store the maximum product.
        int min_product = nums[0]; // Create a variable to store the minimum product.
        int result = nums[0]; // Create a variable to store the result.
        for (int i = 1; i < nums.size(); i++) { // Iterate through the numbers.
            int temp = max_product; // Create a variable to store the maximum product.
            max_product = max(max(max_product * nums[i], min_product * nums[i]), nums[i]); // Update the maximum product.
            min_product = min(min(temp * nums[i], min_product * nums[i]), nums[i]); // Update the minimum product.
            result = max(result, max_product); // Update the result.
        }
        return result; // Return the result.
        
    }
};

int main()
{
    vector<int> nums = {2,3,-2,4};
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}