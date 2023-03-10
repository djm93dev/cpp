#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(); // set m to board.size()
        int n = board[0].size(); // set n to board[0].size()
        for (int i = 0; i < m; i++) { // for i from 0 to m
            for (int j = 0; j < n; j++) { // for j from 0 to n
                int count = 0; // set count to 0
                for (int I = max(i - 1, 0); I < min(i + 2, m); I++) { // for I from max(i - 1, 0) to min(i + 2, m)
                    for (int J = max(j - 1, 0); J < min(j + 2, n); J++) { // for J from max(j - 1, 0) to min(j + 2, n)
                        count += board[I][J] & 1; // set count to count + board[I][J] & 1
                    }
                }
                if (count == 3 || count - board[i][j] == 3) { // if count is 3 or count - board[i][j] is 3
                    board[i][j] |= 2; // set board[i][j] to board[i][j] | 2
                }
            }
        }
        for (int i = 0; i < m; i++) { // for i from 0 to m
            for (int j = 0; j < n; j++) { // for j from 0 to n
                board[i][j] >>= 1; // set board[i][j] to board[i][j] >> 1
            }
        }
        
    }
};

int main() {
    Solution s;
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    s.gameOfLife(board);
    return 0;
}