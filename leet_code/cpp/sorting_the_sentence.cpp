#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        // split the string into words
        string word;
        vector<string> words;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word); // add the word to the words vector
                word = ""; // reset the word
            }
            else
                word += s[i]; // add the character to the word
        }
        words.push_back(word);
        // sort the words
        sort(words.begin(), words.end(), [](string a, string b) { // sort the words by the last character
            return a[a.size() - 1] < b[b.size() - 1];
        });
        // remove the numbers from the words
        for (int i = 0; i < words.size(); i++) // loop through the words
            words[i] = words[i].substr(0, words[i].size() - 1); // remove the last character from the word
        // join the words into a string
        string ans;
        for (int i = 0; i < words.size(); i++) { // loop through the words
            ans += words[i]; // add the word to the ans string
            if (i != words.size() - 1) // if the word is not the last word
                ans += " "; // add a space to the ans string
        }
        return ans; 
    }
};

int main() {
    Solution sol;
    string s = "is2 sentence4 This1 a3";
    cout << sol.sortSentence(s) << endl;
}