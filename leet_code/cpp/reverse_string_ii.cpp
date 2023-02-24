#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {

        for (int i = 0; i < s.size(); i += 1 * k)
        {
            int j = i + k - 1;
            if (j >= s.size())
                j = s.size() - 1;
            std::reverse(s.begin() + i, s.begin() + j + 1);
        }
        return s;
        
    }
};

int main()
{
    Solution s;
    std::cout << s.reverseStr("abcdefg", 2) << std::endl;
    return 0;

}