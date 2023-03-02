#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return; // if board is empty, return
        int m = board.size(), n = board[0].size(); // init m, n
        for (int i = 0; i < m; i++) { // loop board
            if (board[i][0] == 'O') dfs(board, i, 0); // if board[i][0] == 'O', dfs
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1); // if board[i][n - 1] == 'O', dfs
        }
        for (int j = 0; j < n; j++) { // loop board
            if (board[0][j] == 'O') dfs(board, 0, j); // if board[0][j] == 'O', dfs
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j); // if board[m - 1][j] == 'O', dfs
        }
        for (int i = 0; i < m; i++) { // loop board
            for (int j = 0; j < n; j++) { // loop board
                if (board[i][j] == 'O') board[i][j] = 'X'; // if board[i][j] == 'O', board[i][j] = 'X'
                if (board[i][j] == '1') board[i][j] = 'O'; // if board[i][j] == '1', board[i][j] = 'O'
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j) { // dfs
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return; // if out of range or board[i][j] != 'O', return
        board[i][j] = '1'; // board[i][j] = '1'
        dfs(board, i - 1, j);
        dfs(board, i + 1, j); 
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }


};

int main() {
    Solution s;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    s.solve(board);
    return 0;
}