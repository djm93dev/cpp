#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0; // result (default is 0)
        string temp = word; // temp string
        while (sequence.find(temp) != string::npos) { // while the temp string is in the sequence
            ans++; // update the result
            temp += word; // update the temp string
        }
        return ans; // return the result  
    }
};

int main() {
    Solution sol;
    cout << sol.maxRepeating("ababc", "ab") << endl;
    cout << sol.maxRepeating("ababc", "ba") << endl;
    cout << sol.maxRepeating("ababc", "ac") << endl;
    cout << sol.maxRepeating("aaa", "a") << endl;
    return 0;
}