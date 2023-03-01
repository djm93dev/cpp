#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(); // set row to the size of matrix
        int col = matrix[0].size(); // set col to the size of the first row of matrix
        int temp; // create a temp variable
        // create a for loop to iterate through the matrix
        for (int i = 0; i < row; i++) { // iterate through the rows
            for (int j = i; j < col; j++) { // iterate through the columns
                temp = matrix[i][j]; // set temp to the current element
                matrix[i][j] = matrix[j][i]; // set the current element to the element in the same column but different row
                matrix[j][i] = temp; // set the element in the same column but different row to temp
            }
        }
        // create a for loop to reverse the rows
        for (int i = 0; i < row; i++) { // iterate through the rows
            reverse(matrix[i].begin(), matrix[i].end()); // reverse the elements in the current row
        }
        
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix);
    for (auto row : matrix) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}