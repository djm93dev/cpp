#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        std::reverse(s.begin(), s.end());
        
    }
};

int main()
{
    Solution s;
    vector<char> v{'h','e','l','l','o'};
    s.reverseString(v);
    for (auto e : v)
        std::cout << e;
    std::cout << '\n';

    return 0;
}