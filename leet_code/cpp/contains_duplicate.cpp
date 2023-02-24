#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // create a vector of the same size as nums
        vector<int> v(nums.size());
        // copy nums into v
        copy(nums.begin(), nums.end(), v.begin());
        // sort v
        sort(v.begin(), v.end());
        // remove consecutive (adjacent) duplicates
        auto last = unique(v.begin(), v.end());
        v.erase(last, v.end());
        // compare the size of v and nums
        if (v.size() == nums.size()) {
            return false;
        } else {
            return true;
        }

    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,3,4,5,6,7,8,8,10};
    bool result = s.containsDuplicate(v);
    cout << result << endl;

}