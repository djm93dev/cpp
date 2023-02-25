#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        return is_permutation(s.begin(), s.end(), t.begin());
        
    }
};

int main() {
    Solution sol;
    std::cout << sol.isAnagram("anagram", "nagaram") << std::endl;
    std::cout << sol.isAnagram("rat", "car") << std::endl;
    return 0;
}