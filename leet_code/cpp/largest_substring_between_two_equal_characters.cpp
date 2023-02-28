#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1; // result (default is -1)
        for (int i = 0; i < s.size(); i++) { // loop through the string from the beginning
            for (int j = s.size() - 1; j > i; j--) { // loop through the string from the end
                if (s[i] == s[j]) { // if the characters are the same
                    ans = max(ans, j - i - 1); // update the result
                }
            }
        }
        return ans; // return the result
        
    }
};

int main() {
    Solution sol;
    cout << sol.maxLengthBetweenEqualCharacters("aa") << endl;
    cout << sol.maxLengthBetweenEqualCharacters("abca") << endl;
    cout << sol.maxLengthBetweenEqualCharacters("cbzxy") << endl;
    cout << sol.maxLengthBetweenEqualCharacters("cabbac") << endl;
    return 0;
}

