#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// You are given a string s. Reorder the string using the following algorithm:

// Pick the smallest character from s and append it to the result.
// Pick the smallest character from s which is greater than the last appended character to the result and append it.
// Repeat step 2 until you cannot pick more characters.
// Pick the largest character from s and append it to the result.
// Pick the largest character from s which is smaller than the last appended character to the result and append it.
// Repeat step 5 until you cannot pick more characters.
// Repeat the steps from 1 to 6 until you pick all characters from s.
// In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

// Return the result string after sorting s with this algorithm.

class Solution {
public:
    string sortString(string s) {
        string ans;
        sort(s.begin(), s.end());
        while (s.size() > 0) {
            char last = s[0];
            ans += last;
            s.erase(s.begin());
            for (int i = 0; i < s.size(); i++) {
                if (s[i] > last) {
                    ans += s[i];
                    last = s[i];
                    s.erase(s.begin() + i);
                    // we need to decrement i because we just removed an element
                    i--;
                }
            }
            // if we have more elements in s, we need to do the same thing in reverse
            if (s.size() > 0) {
                last = s[s.size() - 1];
                ans += last;
                s.erase(s.end() - 1);
                for (int i = s.size() - 1; i >= 0; i--) {
                    if (s[i] < last) {
                        ans += s[i];
                        last = s[i];
                        s.erase(s.begin() + i);
                    }
                }
            }
        }
        cout << ans << endl;
        return ans;         
        
    }
};

int main() {
    Solution sol;
    string s = "aaaabbbbcccc";
    sol.sortString(s);
}