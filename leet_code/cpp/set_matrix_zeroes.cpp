#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // get the number of rows
        int n = matrix[0].size(); // get the number of columns
        vector<int> rows(m, 0); // create a vector of size m and initialize all elements to 0
        vector<int> cols(n, 0); // create a vector of size n and initialize all elements to 0
        for (int i = 0; i < m; i++) { // iterate through the rows
            for (int j = 0; j < n; j++) { // iterate through the columns
                if (matrix[i][j] == 0) { // if the current element is 0
                    rows[i] = 1; // set the corresponding element in the rows vector to 1
                    cols[j] = 1; // set the corresponding element in the cols vector to 1
                }
            }
        }
        for (int i = 0; i < m; i++) { // iterate through the rows
            for (int j = 0; j < n; j++) { // iterate through the columns
                if (rows[i] == 1 || cols[j] == 1) { // if the corresponding element in the rows vector or the cols vector is 1
                    matrix[i][j] = 0; // set the current element to 0
                }
            }
        }   
        
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    Solution s;
    s.setZeroes(matrix);
    return 0;
}