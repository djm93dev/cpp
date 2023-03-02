#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>> &board,vector<vector<int>> &visited,string &word,int i,int j,int idx){
        if(idx == word.size()) return true; // if the index is equal to the size of the word, return true

        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] == 1 || board[i][j] != word[idx]){ // if the index is out of bounds or the current element is visited or the current element is not equal to the current index of the word, return false
            return false; // return false
        }

        visited[i][j] = 1; // mark the current element as visited

        // traversing all side
        bool ls = dfs(board,visited,word,i,j-1,idx+1); // left
        bool rs = dfs(board,visited,word,i,j+1,idx+1); // right
        bool ds = dfs(board,visited,word,i+1,j,idx+1); // down
        bool us = dfs(board,visited,word,i-1,j,idx+1); // up

        
        visited[i][j] = 0; // // Backtracking (If no one is found suitable match)

        return ls | rs | ds | us; // return true if any of the side is true
    }
public:
    bool exist(vector<vector<char>>& board, string word) { // function to check if the word exists in the board
        int n = board.size(); // get the size of the board
        int m = board[0].size(); // get the size of the board
        vector<vector<int>> visited(n,vector<int>(m,0)); // create a visited matrix

        for(int i=0;i<n;i++){ // traverse the board
            for(int j=0;j<m;j++){ // traverse the board
                if(visited[i][j] == 0 && word[0] == board[i][j]){ // if the current element is not visited and the first element of the word is equal to the current element
                    if(dfs(board,visited,word,i,j,0)){ // call the dfs function
                        return true; // if the dfs function returns true, return true
                    }
                }
            }
        }

        return false; // if the dfs function returns false, return false
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::cout << s.exist(board, "ABCCED") << std::endl;
    return 0;
}