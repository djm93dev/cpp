#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            // check if the character is a space and the next character is not a space
            if (s[i] == ' ' && s[i + 1] != ' ' && i != s.size() - 1)
                ans++; // increment ans
        if (s.size() == 0) // if the size of the string is 0, then return 0
            return 0;
        else if (s.size() == 1 && s[0] != ' ') // if the size of the string is 1 and the character is not a space, then return 1
            return 1;
        else if (s[0] != ' ') // if the first character is not a space, then increment ans
            ans++;
        return ans;
    }
};

int main()
{
    string s = "Hello, my name is John";
    Solution sol;
    int ans = sol.countSegments(s);
    cout << ans << endl;
    return 0;
}