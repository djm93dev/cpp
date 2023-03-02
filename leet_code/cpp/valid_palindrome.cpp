#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; // set the left pointer
        int right = s.size() - 1; // set the right pointer
        while (left < right) { // while the left pointer is less than the right pointer
            if (!isalnum(s[left])) { // if the left pointer is not alphanumeric
                left++; // increment the left pointer
            }
            else if (!isalnum(s[right])) { // if the right pointer is not alphanumeric
                right--; // decrement the right pointer
            }
            else if (tolower(s[left]) != tolower(s[right])) { // if the left pointer is not equal to the right pointer
                return false; // return false
            }
            else { // otherwise
                left++; // increment the left pointer
                right--; // decrement the right pointer
            }
        }
        return true; // return true

        
    }
};

int main() {
    Solution s;
    return 0;
}