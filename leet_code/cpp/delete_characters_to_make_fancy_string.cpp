#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        int count = 0, prevC = s[0], i = 0; // i is the index of the new string
        for (char c: s) { // c is the current character
            if (c == prevC) { // if the current character is the same as the previous one
                count++; // increase the count
            }
            else {
                prevC = c; // if the current character is different from the previous one, update the previous character
                count = 1; // reset the count
            }
            if (count < 3) s[i++] = c; // if the count is less than 3, add the current character to the new string
        }
        s.resize(i); // resize the new string
        return s; // return the new string
    }
};

int main()
{
    Solution s;
    string str = "aaabaaaa";
    string result = s.makeFancyString(str);
    cout << result << endl;

}