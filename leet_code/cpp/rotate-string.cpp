#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        int i = 0;
        int j = 0;
        int k = 0;
        int len = s.length();
        int len2 = goal.length();
        if (len != len2) {
            return false;
        }
        for (i = 0; i < len; i++) {
            if (s[i] == goal[0]) {
                k = i;
                for (j = 0; j < len; j++) {
                    if (s[k] != goal[j]) {
                        break;
                    }
                    k++;
                    if (k == len) {
                        k = 0;
                    }
                }
                if (j == len) {
                    return true;
                }
            }
        }
        return false;

    }
};

 
int main()
{

    Solution s;
    string s1 = "abcde";
    string s2 = "cdeab";
    cout << s.rotateString(s1, s2) << endl;
    return 0;


}