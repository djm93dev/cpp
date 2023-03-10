#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(); // set row to matrix.size()
        int col = matrix[0].size(); // set col to matrix[0].size()
        int i = 0; // set i to 0
        int j = col - 1; // set j to col - 1
        while (i < row && j >= 0) { // while i is less than row and j is greater than or equal to 0
            if (matrix[i][j] == target) { // if matrix[i][j] is equal to target
                return true; // return true
            } else if (matrix[i][j] > target) { // else if matrix[i][j] is greater than target
                j--; // decrement j
            } else { // else
                i++; // increment i
            }
        }
        return false; // return false
        
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,   4,  7, 11, 15},
                                  {2,   5,  8, 12, 19},
                                  {3,   6,  9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 5;
    bool result = s.searchMatrix(matrix, target);
    cout << result << endl;
    return 0;
}