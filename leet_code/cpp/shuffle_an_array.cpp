#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> original, shuffled; // original and shuffled arrays
  int n; // size of the array
  
  Solution(vector<int>& nums) {
    original = nums; // set original to nums
    shuffled = nums; // set shuffled to nums
    n = nums.size(); // set n to the size of nums
  }
    
  vector<int> reset() {
    return original; // return original
  }
    
  vector<int> shuffle() {  
    swap(shuffled[rand()%n], shuffled[rand()%n]); // swap two random elements in shuffled
    return shuffled; // return shuffled
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
  vector<int> nums = {1, 2, 3};
  Solution s(nums);
  cout << s.shuffle() << endl;
  cout << s.reset() << endl;
  cout << s.shuffle() << endl;
  return 0;
}