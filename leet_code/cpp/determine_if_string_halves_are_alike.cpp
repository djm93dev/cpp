#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        string one;
        string two;
        for (int i = 0; i < s.size() / 2; i++) // for each char in first half of s
            one += s[i]; // add char to one
        for (int j = s.size() / 2; j < s.size(); j++) // for each char in second half of s
            two += s[j]; // add char to two
        int count_one = 0;
        int count_two = 0;

        for (int i = 0; i < one.size(); i++) // for each char in one
            if (one[i] == 'a' || one[i] == 'e' || one[i] == 'i' || one[i] == 'o' || one[i] == 'u' || one[i] == 'A' || one[i] == 'E' || one[i] == 'I' || one[i] == 'O' || one[i] == 'U') // if char is a vowel
                count_one++; // increment count_one
        for (int i = 0; i < two.size(); i++) // for each char in two
            if (two[i] == 'a' || two[i] == 'e' || two[i] == 'i' || two[i] == 'o' || two[i] == 'u' || two[i] == 'A' || two[i] == 'E' || two[i] == 'I' || two[i] == 'O' || two[i] == 'U') // if char is a vowel
                count_two++; // increment count_two
        if (count_one == count_two) // if count_one is equal to count_two
            return true; // return true
        return false; // else return false
    }
};

int main() {
    Solution s;
    string s1 = "book";
    cout << s.halvesAreAlike(s1);
}