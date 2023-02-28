#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countNeg = 0; // count negative numbers
        for(auto x: nums){ // for each number in nums
            if(x < 0) // if negative
                countNeg++; // increment count
            else if(x == 0) // if zero
                return 0; // return 0
        }
        if(countNeg%2 ==0) // if even number of negatives
            return 1; // return 1
        return -1; // else return -1
    }
};

int main()
{
    Solution s;
    vector<int> nums = {9,72,34,29,-49,-22,-77,-17,-66,-75,-44,-30,-24};
    std::cout << s.arraySign(nums) << std::endl;
    return 0;
}