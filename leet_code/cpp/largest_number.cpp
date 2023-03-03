#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s; // create a vector to store the strings of the numbers
        for (int i = 0; i < nums.size(); i++) { // loop through the numbers
            s.push_back(to_string(nums[i])); // add the string of the number to the vector
        }
        sort(s.begin(), s.end(), [](string a, string b) {return a + b > b + a;}); // sort the vector of strings in descending order
        string res; // create a string to store the result
        for (int i = 0; i < s.size(); i++) { // loop through the vector of strings
            res += s[i]; // add the string to the result
        }
        while (res[0] == '0' && res.size() > 1) { // while the first character of the result is 0 and the result is not 0
            res.erase(0, 1); // erase the first character of the result
        }
        return res; // return the result
            
        
    }
};

int main()
{
    Solution s;
    cout << s.largestNumber({3, 30, 34, 5, 9}) << endl;
    return 0;
}