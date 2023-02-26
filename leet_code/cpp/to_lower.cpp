#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for(int i=0; i < s.size(); i++)
           ans.push_back(tolower(s[i]));
        cout << ans << endl;
        return ans;
        
    }
};

int main() {
    Solution sol;
    string s = "Hello";
    sol.toLowerCase(s);
}