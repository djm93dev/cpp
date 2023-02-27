#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        string prefix;
        for (int i = 0; i < word.size(); i++)
            if (word[i] != ch)
                prefix += word[i];
            else {
                prefix += word[i];
                break;
            }
        reverse(prefix.begin(), prefix.end());
        for (int i = 0; i < prefix.size(); i++)
            word[i] = prefix[i];

        
        return word;
                
        
    }
};

int main() {
    Solution s;
    string word = "abcdefd";
    char ch = 'd';
    cout << s.reversePrefix(word, ch);
}