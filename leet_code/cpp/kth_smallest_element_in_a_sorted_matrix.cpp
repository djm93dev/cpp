#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); // number of rows
        int m = matrix[0].size(); // number of columns
        int l = matrix[0][0]; // left
        int r = matrix[n - 1][m - 1]; // right
        while (l < r) { // while left is less than right
            int mid = l + (r - l) / 2; // mid
            int count = 0; // number of elements less than or equal to mid
            int j = m - 1; // column index
            for (int i = 0; i < n; i++) { // for each row
                while (j >= 0 && matrix[i][j] > mid) { // while column index is greater than or equal to 0 and the element is greater than mid
                    j--; // decrease column index
                }
                count += (j + 1); // update count
            }
            if (count < k) { // if count is less than k
                l = mid + 1; // update left
            } else { // if count is greater than or equal to k
                r = mid; // update right
            }
        }
        return l; // return left
        
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    cout << s.kthSmallest(matrix, k) << endl;
    return 0;
}