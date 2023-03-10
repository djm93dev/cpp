#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(); // size of s
        if (n == 0 || k > n) { // if s is empty or k is greater than n
            return 0; // return 0
        }
        if (k <= 1) { // if k is less than or equal to 1
            return n; // return n
        }
        unordered_map<char, int> m; // map of characters to their frequencies
        for (char c : s) { // for each character in s
            m[c]++; // increment the frequency of c
        }
        int i = 0; // index of s
        while (i < n && m[s[i]] >= k) { // while i is less than n and the frequency of the i-th character in s is greater than or equal to k
            i++; // increment i
        }
        if (i == n) { // if i is equal to n
            return n; // return n
        }
        int left = longestSubstring(s.substr(0, i), k); // longest substring of the first i characters in s
        while (i < n && m[s[i]] < k) { // while i is less than n and the frequency of the i-th character in s is less than k
            i++; // increment i
        }
        int right = longestSubstring(s.substr(i), k); // longest substring of the last n - i characters in s
        return max(left, right); // return the maximum of left and right
        
    }
};

int main() {
    Solution s;
    string s = "aaabb";
    int k = 3;
    cout << s.longestSubstring(s, k) << endl;
    return 0;
}