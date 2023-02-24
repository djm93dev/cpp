#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
 
struct ReverseWords
{
    void operator()(std::string& x) { std::reverse(x.begin(), x.end()); }
};

class Solution {
public:
    string reverseWords(string s) {
    std::string string = s;
    std::vector<std::string> x;
    std::string word;
    for (auto& c : string)
    {
        if (c == ' ')
        {
            x.push_back(word);
            word = "";
        }
        else if (&c == &string.back())
        {
            word += c;
            x.push_back(word);
        }
        else
        {
            word += c;
        }
    }
    
    std::for_each(x.begin(), x.end(), ReverseWords());

    // convert vector to string
    std::string result;
    for (auto& c : x)
    {
        result += c;
        result += " ";
    }
    result.pop_back();


    return result;
    }
};

int main()
{
    Solution s;
    std::string x = "Let's take LeetCode contest";
    s.reverseWords(x);
    return 0;
}