#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        if (word.find(ch) == string::npos) // if ch is not in word
            return word; // return word
        string prefix;
        for (int i = 0; i < word.size(); i++) // for each char in word
            if (word[i] != ch) // if char is not equal to ch
                prefix += word[i]; // add char to prefix
            else {
                prefix += word[i]; // add char to prefix
                break; // break out of loop if char is equal to ch
            }
        reverse(prefix.begin(), prefix.end()); // reverse prefix
        for (int i = 0; i < prefix.size(); i++) // for each char in prefix
            word[i] = prefix[i]; // replace char in word with char in prefix

        
        return word; // return word
                
        
    }
};

int main() {
    Solution s;
    string word = "abcdefd";
    char ch = 'd';
    cout << s.reversePrefix(word, ch);
}