#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string two;
        string one;
        for (int i = 0; i < word1.size(); i++) // for each string in word1
            for (int j = 0; j < word1[i].size(); j++) // for each char in string
                one += word1[i][j]; // add char to one
        for (int k = 0; k < word2.size(); k++) // for each string in word2
            for (int x = 0; x < word2[k].size(); x++) // for each char in string
                two += word2[k][x]; // add char to two
        if (one == two) // if one and two are equal
            return true; // return true
        return false; // else return false
    }
};

int main() {
    Solution s;
    vector<string> word1 = { "ab", "c" };
    vector<string> word2 = { "a", "bc" };
    cout << s.arrayStringsAreEqual(word1, word2);
}