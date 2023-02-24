#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        std::vector<char> target_vec;
        target_vec.push_back(target);
        auto it = std::upper_bound(letters.begin(), letters.end(), target);
        if (it == letters.end()) {
            return letters[0];
        } else {
            return *it;
        }
    }
};