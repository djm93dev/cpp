#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        for (int i = 0; i < allowed.size(); i++) // for each char in allowed
            for (int j = 0; j < words.size(); j++) // for each string in words
                for (int k = 0; k < words[j].size(); k++) // for each char in string
                    if (allowed[i] == words[j][k]) // if char in allowed is equal to char in string
                        words[j][k] = ' '; // replace char in string with space
        int count = 0;

        for (int i = 0; i < words.size(); i++) { // for each string in words
            int j = 0;
            for (; j < words[i].size(); j++) // for each char in string
                if (words[i][j] != ' ') // if char is not a space
                    break;
            if (j == words[i].size()) // if j is equal to the size of the string
                count++;
        }
        return count;
 
        
    }
};

int main() {
    Solution s;
    string allowed = "ab";
    vector<string> words = { "ad", "bd", "aaab", "baa", "badab" };
    cout << s.countConsistentStrings(allowed, words);
}