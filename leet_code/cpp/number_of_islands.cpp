#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0; // initialize count to 0
        int m = grid.size(); // set m to the size of the vector
        if (m == 0) return 0; // if the vector is empty return 0
        int n = grid[0].size(); // set n to the size of the first element of the vector
        if (n == 0) return 0; // if the first element of the vector is empty return 0
        for (int i = 0; i < m; i++) { // loop through the vector
            for (int j = 0; j < n; j++) { // loop through the first element of the vector
                if (grid[i][j] == '1') { // if the current element is equal to 1
                    count++; // increment count
                    queue<pair<int, int>> q; // create a queue of pairs
                    q.push(make_pair(i, j)); // push the current element to the queue
                    while (!q.empty()) { // while the queue is not empty
                        pair<int, int> p = q.front(); // set p to the front of the queue
                        q.pop(); // pop the front of the queue
                        int x = p.first; // set x to the first element of p
                        int y = p.second; // set y to the second element of p
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') { // if x is greater than or equal to 0 and less than m and y is greater than or equal to 0 and less than n and the element at grid[x][y] is equal to 1
                            grid[x][y] = '0'; // set the element at grid[x][y] to 0
                            q.push(make_pair(x - 1, y)); // push the elements to the queue
                            q.push(make_pair(x + 1, y)); // push the elements to the queue
                            q.push(make_pair(x, y - 1)); // push the elements to the queue
                            q.push(make_pair(x, y + 1)); // push the elements to the queue
                        }
                    }
                }
            }
        }
        return count; // return count
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << s.numIslands(grid) << endl;
    return 0;
}