#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // copy the paragraph to a new string vector and remove all the punctuations
        vector<string> words;
        string word = "";
        for (int i = 0; i < paragraph.size(); i++) {
            if (isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            } else {
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        if (word != "") {
            words.push_back(word);
        }
        // check if the word is in the banned list
        for (int i = 0; i < words.size(); i++) {
            if (find(banned.begin(), banned.end(), words[i]) != banned.end()) {
                words.erase(words.begin() + i);
                i--;
            }
        }
        // find the most common word
        int max_count = 0;
        string max_word = "";
        for (int i = 0; i < words.size(); i++) {
            int count = 0;
            for (int j = 0; j < words.size(); j++) {
                if (words[i] == words[j]) {
                    count++;
                }
            }
            if (count > max_count) {
                max_count = count;
                max_word = words[i];
            }
        }
        return max_word;
    }
};
          

int main() {
    Solution s;
    vector<string> banned = {"hit"};
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    cout << s.mostCommonWord(paragraph, banned) << endl;
    return 0;
}