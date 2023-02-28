#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false; // if the size is not equal, return false
        if (s == goal) { // if the two strings are equal, check if there are any duplicate characters
            vector<int> count(26, 0); // create a vector of size 26, and initialize all values to 0
            for (char c : s) { // for each character in s
                count[c - 'a']++; // increment the count of the character
                if (count[c - 'a'] > 1) return true; // if the count is greater than 1, return true
            }
            return false; // if the count is not greater than 1, return false
        }
        vector<int> diff; // create a vector to store the index of the characters that are different
        for (int i = 0; i < s.size(); i++) { // for each character in s
            if (s[i] != goal[i]) diff.push_back(i); // if the characters are different, add the index to the vector
        }
        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]; // if the size of the vector is 2, and the characters at the indices are swapped, return true, else return false

        
    }
};

int main() {
    Solution s;
    string s1 = "ab";
    string s2 = "ba";
    cout << s.buddyStrings(s1, s2) << endl;
    return 0;
}