#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result; // create a vector of vector of string
        vector<string> path; // create a vector of string
        dfs(s, 0, path, result); // call the dfs function
        return result; // return the result
        
    }

    void dfs(string s, int start, vector<string> &path, vector<vector<string>> &result) { // dfs function
        if (start == s.size()) { // if start is equal to the size of the string
            result.push_back(path); // push the path into the result
            return;
        }
        for (int i = start; i < s.size(); i++) { // for loop to iterate through the string
            if (isPalindrome(s, start, i)) { // if the string is a palindrome
                path.push_back(s.substr(start, i - start + 1)); // push the string into the path
                dfs(s, i + 1, path, result); // call the dfs function
                path.pop_back(); // pop the string from the path
            }
        }
    }

    bool isPalindrome(string s, int start, int end) { // function to check if the string is a palindrome
        while (start < end) { // while loop to iterate through the string
            if (s[start] != s[end]) { // if the string is not a palindrome
                return false; // return false
            }
            start++; // increment start
            end--; // decrement end
        }
        return true; // return true
    }

};

int main()
{
    Solution s;
    s.partition("aab");
    return 0;
}