#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // Create a set of the words in the dictionary.
        vector<vector<string>> dp(s.size() + 1); // Create a vector of vectors of strings.
        dp[0].push_back(""); // Add an empty string to the first vector.
        for (int i = 1; i <= s.size(); i++) { // For each index in the string.
            for (int j = 0; j < i; j++) { // For each index before the current index.
                if (dp[j].size() > 0 && wordSet.find(s.substr(j, i - j)) != wordSet.end()) { // If the vector at the current index is not empty and the substring from the current index to the end of the string is in the set.
                    for (string str : dp[j]) { // For each string in the vector at the current index.
                        dp[i].push_back(str + (str == "" ? "" : " ") + s.substr(j, i - j)); // Add the string to the vector at the next index.
                    }
                }
            }
        }
        return dp[s.size()]; // Return the vector at the last index.
        
    }

};

int main()
{
    Solution s;
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result = s.wordBreak("catsanddog", wordDict);
    for (string str : result) {
        cout << str << endl;
    }
    return 0;
}