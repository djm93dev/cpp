#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> nums; // create a vector to store the numbers
        while (n != 1) { // while n is not equal to 1
            int sum = 0; // initialize sum to 0
            while (n > 0) { // while n is greater than 0
                sum += (n % 10) * (n % 10); // add the square of the last digit to sum
                n /= 10; // divide n by 10
            }
            n = sum; // set n to sum
            for (int i = 0; i < nums.size(); i++) { // loop through the vector
                if (nums[i] == n) return false; // if the current element is equal to n return false
            }
            nums.push_back(n); // push n to the vector
        }
        return true; // return true
        
    }
};

int main()
{
    Solution s;
    cout << s.isHappy(19) << endl;
    return 0;
}