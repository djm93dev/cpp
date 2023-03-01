#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); // get the size of the vector
        for(int i = 0; i < n; i++){ // iterate through the vector
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) // while the current element is greater than 0 and less than or equal to the size of the vector and the element at the index of the current element minus 1 is not equal to the current element
                swap(nums[i], nums[nums[i] - 1]);   // swap the current element with the element at the index of the current element minus 1
        }
        for(int i = 0; i < n; i++){ // iterate through the vector
            if(nums[i] != i + 1) // if the current element is not equal to the index plus 1
                return i + 1; // return the index plus 1
        }
        return n + 1; // otherwise return the size of the vector plus 1
         
    }
};

int main(){
    vector<int> nums = {1, 2, 0};
    Solution s;
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}