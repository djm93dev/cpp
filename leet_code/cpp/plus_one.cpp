#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) { // loop from the end
            if (digits[i] < 9) { // if the digit is less than 9, add 1 and return
                digits[i]++; // add 1
                return digits; // return the vector
            }
            digits[i] = 0; // if the digit is 9, set it to 0
        }
        digits.insert(digits.begin(), 1); // if the vector was 9, add a 1 to the front
        return digits; // return the vector
        vector<int> ans; // create a new vector
        for(int i = 0; i < digits.size(); i++) // loop through the vector 
            if (i == digits.size() - 1) // if i is the last digit
                digits[i] = digits[i] + 1, ans.push_back(digits[i]), // add 1 to the last digit and push it to the vector
                ans.push_back(digits[i]); // push the digit to the vector
            else
                ans.push_back(digits[i]); // push the digit to the vector
        return ans; // return the vector
        
    }
};

int main() {
    vector<int> digits = {1, 2, 3};
    Solution s;
    vector<int> ans = s.plusOne(digits);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}