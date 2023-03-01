#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParenthesisHelper(vector<string>& ans, string s, int left, int right) { // helper function to generate the parentheses
    if (left == 0 && right == 0) { // if the number of left and right parentheses is 0, add the string to the vector
        ans.push_back(s); // add the string to the vector
        return; // return
    }
    if (left > 0) { // if the number of left parentheses is greater than 0, add a left parentheses
        generateParenthesisHelper(ans, s + "(", left - 1, right); // call the helper function
    }
    if (right > left) { // if the number of right parentheses is greater than the number of left parentheses, add a right parentheses
        generateParenthesisHelper(ans, s + ")", left, right - 1); // call the helper function
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; // create a vector to store the strings
        string s; // create a string to store the parentheses
        generateParenthesisHelper(ans, s, n, n); // call the helper function
        return ans; // return the vector
        
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}