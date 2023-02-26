#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        string ans;
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < t.size(); j++)
                if (s[i] == t[j]) {
                    ans += s[i];
                    t = t.substr(j + 1);
                    break;
                }
        return ans == s;
    }
};

int main() {
    Solution sol;
    string s = "abc", t = "ahbgdc";
    cout << sol.isSubsequence(s, t) << endl;
}