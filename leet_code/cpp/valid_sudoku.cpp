#include <iostream>
#include <vector>


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false)); // initialize a 9x9 vector of booleans to store the rows default to false
        vector<vector<bool>> col(9, vector<bool>(9, false)); // initialize a 9x9 vector of booleans to store the columns default to false
        vector<vector<bool>> box(9, vector<bool>(9, false)); // initialize a 9x9 vector of booleans to store the boxes default to false
        for(int i = 0; i < 9; i++){ // iterate through the rows
            for(int j = 0; j < 9; j++){ // iterate through the columns
                if(board[i][j] != '.'){ // if the element is not a '.'
                    int num = board[i][j] - '0' - 1; // convert the element to an integer
                    int k = i / 3 * 3 + j / 3; // calculate the box index
                    if(row[i][num] || col[j][num] || box[k][num]) // if the row, column, or box already contains the number
                        return false; // return false
                    row[i][num] = col[j][num] = box[k][num] = true; // otherwise, set the row, column, and box to true
                }
            }
        }
        return true; // if the board is valid, return true
        
    }
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    Solution s;
    cout << s.isValidSudoku(board) << endl;
    return 0;
}