#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

// A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

// For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
// Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        // split the string into words
        string word;
        vector<string> words;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else
                word += s[i];
        }
        words.push_back(word);
        // sort the words
        sort(words.begin(), words.end(), [](string a, string b) {
            return a[a.size() - 1] < b[b.size() - 1];
        });
        // remove the numbers from the words
        for (int i = 0; i < words.size(); i++)
            words[i] = words[i].substr(0, words[i].size() - 1);
        // join the words into a string
        string ans;
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += " ";
        }
        return ans;



                
        
    }
};

int main() {
    Solution sol;
    string s = "is2 sentence4 This1 a3";
    cout << sol.sortSentence(s) << endl;
}