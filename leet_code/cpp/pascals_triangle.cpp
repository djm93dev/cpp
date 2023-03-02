#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; // create a vector of vectors
        for (int i = 0; i < numRows; i++) { // for each row
            vector<int> row; // create a vector
            for (int j = 0; j <= i; j++) { // for each element in the row
                if (j == 0 || j == i) { // if the element is the first or last element
                    row.push_back(1); // push a 1 into the vector
                }
                else { // if the element is not the first or last element
                    row.push_back(result[i - 1][j - 1] + result[i - 1][j]); // push the sum of the two elements above it into the vector
                }
            }
            result.push_back(row); // push the vector into the vector of vectors
        }
        return result; // return the vector of vectors
        
    }
};

int main() {
    Solution s;
    return 0;
}