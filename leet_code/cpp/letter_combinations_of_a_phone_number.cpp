#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

void dfs(string digits, int index, string s, vector<string>& ans, unordered_map<char, string>& m) { // create a depth first search function to find all the combinations
    if (index == digits.size()) { // if the index reaches the end of the digits string, add the combination to the answer
        ans.push_back(s); // add the combination to the answer
        return; // return
    }
    string letters = m[digits[index]]; // get the letters corresponding to the digit
    for (int i = 0; i < letters.size(); i++) { // loop through the letters
        dfs(digits, index + 1, s + letters[i], ans, m); // call the dfs function to find the combinations
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) { // create a function to find all the combinations
        vector<string> ans; // initialize the answer
        if (digits.size() == 0) return ans; // if the digits string is empty, return the answer
        unordered_map<char, string> m = { // create a map to store the letters corresponding to the digits
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string s = ""; // initialize the combination
        dfs(digits, 0, s, ans, m); // call the dfs function to find the combinations
        return ans; // return the answer
    }
};

int main() {
    Solution s;
    string digits = "23";
    vector<string> ans = s.letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;

}