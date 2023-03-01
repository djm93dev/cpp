#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; // Create a vector to store the answer
        int left = 0, right = matrix[0].size() - 1; // Set the left and right pointers
        int top = 0, bottom = matrix.size() - 1; // Set the top and bottom pointers
        while (left <= right && top <= bottom) { // While the left pointer is less than or equal to the right pointer and the top pointer is less than or equal to the bottom pointer
            for (int i = left; i <= right; i++) { // Iterate through the top row
                ans.push_back(matrix[top][i]); // Add the number at the top row and the current index to the answer
            }
            top++; // Increment the top pointer
            for (int i = top; i <= bottom; i++) { // Iterate through the right column
                ans.push_back(matrix[i][right]); // Add the number at the right column and the current index to the answer
            }
            right--; // Decrement the right pointer
            if (top <= bottom) { // If the top pointer is less than or equal to the bottom pointer
                for (int i = right; i >= left; i--) { // Iterate through the bottom row
                    ans.push_back(matrix[bottom][i]); // Add the number at the bottom row and the current index to the answer
                }
                bottom--; // Decrement the bottom pointer
            }
            if (left <= right) { // If the left pointer is less than or equal to the right pointer
                for (int i = bottom; i >= top; i--) { // Iterate through the left column
                    ans.push_back(matrix[i][left]); // Add the number at the left column and the current index to the answer
                }
                left++; // Increment the left pointer
            }
        }
        return ans; // Return the answer

        
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = s.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}