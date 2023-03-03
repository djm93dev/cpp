#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // Create a set of the words in the dictionary.
        vector<bool> dp(s.size() + 1, false); // Create a vector of booleans to keep track of the words that can be made.
        dp[0] = true; // Set the first element to true because it is the empty string.
        for (int i = 1; i <= s.size(); i++) { // Loop through the string.
            for (int j = 0; j < i; j++) { // Loop through the string again.
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) { // If the current element is true and the word is in the dictionary.
                    dp[i] = true; // Set the next element to true.
                    break; // Break out of the loop.
                }
            }
        }
        return dp[s.size()]; // Return the last element of the vector.
        
    }
};

int main()
{
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    Solution s;
    cout << s.wordBreak(s, wordDict) << endl;
    return 0;
}