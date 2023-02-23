#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size();
        if (n == 0) return "";
        if (n == 1) return str;
        int max_len = 1;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < n && str[left] == str[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > max_len) {
                max_len = right - left - 1;
                start = left + 1;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && str[left] == str[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > max_len) {
                max_len = right - left - 1;
                start = left + 1;
            }
        }
        return str.substr(start, max_len);
    }
};

int main() {
    Solution sol;
    string str = "babad";
    cout << sol.longestPalindrome(str) << endl;
    return 0;
}