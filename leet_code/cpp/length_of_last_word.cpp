#include <regex>
#include <iterator>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        std::regex words_regex("[^\\s]+");
        auto words_begin = 
            std::sregex_iterator(s.begin(), s.end(), words_regex);
        auto words_end = std::sregex_iterator();

        std::smatch match;
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            match = *i;
        }

        int length = match.length();
        return length;
        
    }
};

int main()
{
    Solution s;
    std::cout << s.lengthOfLastWord("Hello World") << std::endl;

    return 0;
}