#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

using namespace std;


class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        vector<int> v; // to store the digits of each number
        int sum = 0; // sum of all numbers
        int sumOfDigits = 0; // sum of all digits
        for (int i = 0; i < nums.size(); i++) // loop through all numbers
        {
            sum += nums[i]; // increment sum by each number
            while (nums[i] > 0) {
                v.push_back(nums[i] % 10); // % 10 to get the last digit
                nums[i] /= 10; // /= 10 to remove the last digit
            }
            sumOfDigits += accumulate(v.begin(), v.end(), 0); // 0 is the initial value
            v.clear();
        }
        return sum - sumOfDigits;
        
        
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,15,6,3 };
    int result = s.differenceOfSum(nums);
    std::cout << result << std::endl;

}