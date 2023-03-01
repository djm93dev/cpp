#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // if needle is empty, return 0
        if (haystack.empty()) return -1; // if haystack is empty, return -1
        int i = 0, j = 0; // i is the index of haystack, j is the index of needle
        while (i < haystack.size() && j < needle.size()) { // if i or j is out of range, break
            if (haystack[i] == needle[j]) { // if the current char is equal, move forward
                i++; // increment i
                j++; // increment j
            } else { 
                i = i - j + 1; // if the current char is not equal, move i to the next char
                j = 0; // reset j
            }
        }
        if (j == needle.size()) return i - j; // if j is out of range, return i - j
        return -1; // if i is out of range, return -1
    }
};

int main()
{
    Solution s;
    cout << s.strStr("hello", "ll") << endl;
    cout << s.strStr("aaaaa", "bba") << endl;
    cout << s.strStr("", "") << endl;
    cout << s.strStr("a", "a") << endl;
    cout << s.strStr("mississippi", "issip") << endl;
    return 0;
}