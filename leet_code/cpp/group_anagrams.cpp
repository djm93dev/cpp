#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans; // Create a vector of vectors of strings
        unordered_map<string, vector<string>> M; // Create a map of strings and vectors of strings
        for(int  i = 0; i < strs.size(); i++) // Iterate through the vector of strings
        {
            string str = strs[i]; // Create a string variable and set it to the current string
            sort(strs[i].begin(), strs[i].end()); // Sorting the string
            M[strs[i]].push_back(str);  // Sorted string is the key and the value is the initial string
        }
        for(auto i = M.begin(); i != M.end(); i++) // Traversing the map
            ans.push_back(i -> second);  // Traversing the map and adding the vectors of string to ans
        return ans; // Return the vector of vectors of strings
    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}