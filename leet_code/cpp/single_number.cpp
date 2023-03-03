#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>()); // 0 is the initial value of the accumulator and bit_xor is the binary function that does the operation on the elements. It will return the single number because all the other numbers will cancel out.
    }
};

int main()
{
    vector<int> nums = { 2, 2, 1 };
    Solution s;
    cout << s.singleNumber(nums) << endl;
    return 0;
}