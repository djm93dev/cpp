#include <iostream>
#include <string>


class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, minLeft = 0, minLen = INT_MAX, counter = t.size(); // initialize the left and right pointers, minLeft and minLen, and the counter
        vector<int> map(128, 0); // create a vector of size 128 and initialize all elements to 0
        for (auto c : t) map[c]++; // iterate through the string t and increment the element at the index of the current character
        while (right < s.size()) { // iterate through the string s
            if (map[s[right++]]-- > 0) counter--; // decrement the element at the index of the current character and decrement the counter if the element is greater than 0
            while (counter == 0) { // if the counter is 0
                if (right - left < minLen)  minLeft = left, minLen = right - left; // update the minLeft and minLen
                if (map[s[left++]]++ == 0) counter++;  // increment the element at the index of the current character and increment the counter if the element is 0
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen); // return the substring of s starting at minLeft and of length minLen
        
    }
};

int main() {
    Solution s;
    std::cout << s.minWindow("ADOBECODEBANC", "ABC") << std::endl;
    return 0;
}