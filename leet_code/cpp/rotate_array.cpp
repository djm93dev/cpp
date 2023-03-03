#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size(); // if k is greater than the size of the vector, then we can just rotate the vector by k % nums.size() times
        std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend()); // will rotate the vector in place in O(n) time and O(1) space complexity
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    s.rotate(v, 3);
    for (int n : v)
        cout << n << ' ';
    cout << '\n';
    return 0;
}