#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            string ans = strs[0];
            
            for(int i = 1; i < strs.size(); i++) {
                int j;
                for(j = 0; j < strs[i].size(); j++) {
                    if(ans[j] != strs[i][j])
                        break;
                }
                ans = ans.substr(0, j);
                if(ans == "")
                    return ans;
            }
            
            return ans;
        }
};

int main() {
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    string ans = s.longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}