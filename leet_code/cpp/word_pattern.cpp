#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m; // create unordered map
        unordered_map<string, char> m2; // create unordered map
        int j = 0; // initialize j to 0
        for (int i = 0; i < pattern.size(); i++) { // iterate through pattern
            if (j >= s.size()) // if j is greater than or equal to size of s
                return false; // return false
            string word = ""; // initialize word to empty string
            while (j < s.size() && s[j] != ' ') { // while j is less than size of s and s[j] is not equal to space
                word += s[j]; // add s[j] to word
                j++; // increment j
            }
            j++; // increment j
            if (m.find(pattern[i]) == m.end() && m2.find(word) == m2.end()) { // if pattern[i] is not found in m and word is not found in m2
                m[pattern[i]] = word; // add pattern[i] and word to m and m2
                m2[word] = pattern[i]; // add word and pattern[i] to m2 and m
            }
            else if (m.find(pattern[i]) != m.end() && m2.find(word) != m2.end()) { // if pattern[i] is found in m and word is found in m2
                if (m[pattern[i]] != word || m2[word] != pattern[i]) // if m[pattern[i]] is not equal to word or m2[word] is not equal to pattern[i]
                    return false; // return false
            }
            else // else
                return false; // return false
        }
        if (j < s.size()) // if j is less than size of s
            return false; // return false
        return true; // return true
        
    }
};

int main()
{
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
    cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog dog dog dog") << endl;
}