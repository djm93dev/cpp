#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) // i is the start of the substring
            for (int j = i + 1; j < s.size(); j++) // j is the end of the substring
                if (s[i] == s[j]) // if the first char is equal to the last char
                {
                    ans = s.substr(i, j - i); // get the substring
                    if (ans.size() > s.size() / 2) // if the substring is longer than half of the string,
                        return false; // then it is impossible to be repeated
                    if (s.size() % ans.size() == 0) // if the substring can be repeated
                    {
                        int k = 0; // check if the substring is repeated
                        for (; k < s.size(); k++) // k is the index of the string
                            if (s[k] != ans[k % ans.size()]) // if the char is not equal to the char in the substring
                                break; // break the loop
                        if (k == s.size()) // if the loop is not broken
                            return true; // then the substring is repeated
                    }
                }
        return false; // if the loop is not broken
 
    }
};

int main()
{
    Solution s;
    cout << s.repeatedSubstringPattern("abab") << endl;
    cout << s.repeatedSubstringPattern("aba") << endl;
    cout << s.repeatedSubstringPattern("abcabcabcabc") << endl;
    return 0;
}
