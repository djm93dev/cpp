#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a, int b) { return a + b; }}, // Create a map to store the operations.
            {"-", [](int a, int b) { return a - b; }}, 
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };
        vector<int> stack;
        for (string token : tokens) { // Iterate through the tokens.
            if (operations.find(token) != operations.end()) { // If the token is an operation.
                int b = stack.back(); // Pop the last two elements from the stack.
                stack.pop_back();
                int a = stack.back(); // Pop the last two elements from the stack.
                stack.pop_back();
                stack.push_back(operations[token](a, b)); // Perform the operation and push the result onto the stack.
            }
            else {
                stack.push_back(stoi(token)); // If the token is not an operation, push it onto the stack.
            }
        }
        return stack.back(); // Return the last element on the stack.
        
    }
};

int main ()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution s;
    cout << s.evalRPN(tokens) << endl;
    return 0;
}