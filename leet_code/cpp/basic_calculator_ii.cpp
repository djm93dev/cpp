#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int calculate(string s) {
        int result = 0; // initialize result to 0
        int num = 0; // initialize num to 0
        char op = '+'; // initialize op to +
        stack<int> st; // initialize a stack
        for (int i = 0; i < s.size(); i++) { // for each character in the string
            if (isdigit(s[i])) { // if the character is a digit
                num = num * 10 + (s[i] - '0'); // set num to num * 10 + the character - '0'
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) { // if the character is not a digit and is not a space or i is equal to the size of the string - 1
                if (op == '+') { // if op is +
                    st.push(num); // push num to the stack
                } else if (op == '-') { // if op is -
                    st.push(-num); // push -num to the stack
                } else if (op == '*') { // if op is *
                    int temp = st.top(); // set temp to the top of the stack
                    st.pop(); // pop the top of the stack
                    st.push(temp * num); // push temp * num to the stack
                } else if (op == '/') { // if op is /
                    int temp = st.top(); // set temp to the top of the stack
                    st.pop(); // pop the top of the stack
                    st.push(temp / num); // push temp / num to the stack
                }
                op = s[i]; // set op to the character
                num = 0; // set num to 0
            }
        }
        while (!st.empty()) { // while the stack is not empty
            result += st.top(); // add the top of the stack to result
            st.pop(); // pop the top of the stack
        }
        return result; // return result
        
        
    }
};

int main() {
    Solution s;
    string str = "3+2*20";
    cout << s.calculate(str) << endl;
    return 0;
}