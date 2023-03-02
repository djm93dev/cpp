#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); // get the size of the heights vector
        vector<int> left(n), right(n); // create two vectors to store the left and right index of the current element
        stack<int> mono_stack; // create a stack to store the index of the elements
        for (int i = 0; i < n; ++i) { // traverse the heights vector
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) { // if the stack is not empty and the top element of the stack is greater than or equal to the current element
                mono_stack.pop(); // pop the top element of the stack
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top()); // if the stack is empty, the left index of the current element is -1, else the left index of the current element is the top element of the stack
            mono_stack.push(i); // push the current index into the stack
        }

        mono_stack = stack<int>(); // clear the stack
        for (int i = n - 1; i >= 0; --i) { // traverse the heights vector from the end
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) { // if the stack is not empty and the top element of the stack is greater than or equal to the current element
                mono_stack.pop(); // pop the top element of the stack
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top()); // if the stack is empty, the right index of the current element is n, else the right index of the current element is the top element of the stack
            mono_stack.push(i); // push the current index into the stack
        }

        int ans = 0; // create a variable to store the maximum area
        for (int i = 0; i < n; ++i) { // traverse the heights vector
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]); // calculate the area of the current element and update the maximum area
        }
        return ans; // return the maximum area
        
    }
};

int main() {
    Solution s;
    vector<int> heights = {2,1,5,6,2,3};
    std::cout << s.largestRectangleArea(heights) << std::endl;
    return 0;
}