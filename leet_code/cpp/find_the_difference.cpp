#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        string ans;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < t.size(); i++)
            if (i > s.size() || s[i]!= t[i])
                ans += t[i];
        return ans[0];
    }
};

int main() {
    Solution sol;
    string s = "", t = "y";
    cout << sol.findTheDifference(s, t) << endl;
}