#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        for (auto c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels.push_back(c);
            }
        }
        reverse(vowels.begin(), vowels.end());
        int i = 0;
        for (auto &c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                c = vowels[i++];
            }
        }
        return s;
        
    }
};

int main()
{
    Solution s;
    cout << s.reverseVowels("hello") << endl;
    cout << s.reverseVowels("leetcode") << endl;
    return 0;
}