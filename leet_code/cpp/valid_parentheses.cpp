#include <iostream>
#include <string>
#include <stack>


using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // create stack
        for (int i = 0; i < s.size(); i++) { // iterate through s
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') // if s[i] is equal to (, [, or {
                st.push(s[i]); // push s[i] to stack
            else { // else
                if (st.empty()) // if stack is empty
                    return false; // return false
                char c = st.top(); // initialize c to top of stack
                st.pop(); // pop top of stack
                if (s[i] == ')' && c != '(') // if s[i] is equal to ) and c is not equal to (
                    return false; // return false
                if (s[i] == ']' && c != '[') // if s[i] is equal to ] and c is not equal to [
                    return false; // return false
                if (s[i] == '}' && c != '{') // if s[i] is equal to } and c is not equal to {
                    return false; // return false
            }
        }
        if (!st.empty()) // if stack is not empty
            return false; // return false
        return true; // return true
        
    }
};

int main()
{
    Solution s;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("{[]}") << endl;
}