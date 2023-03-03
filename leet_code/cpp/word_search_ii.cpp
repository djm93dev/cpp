#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>


using namespace std;

class Solution {
    struct TrieNode { 
        TrieNode *children[26]; // 26 letters in the alphabet
        string word; // the word that ends at this node

        TrieNode() : word("") { // constructor
            for (int i = 0; i < 26; i++) { // initialize all children to nullptr
                children[i] = nullptr; // initialize all children to nullptr
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) { // find all words in the board
        TrieNode *root = buildTrie(words); // build a trie from the words
        vector<string> result; // vector to store the result
        for (int i = 0; i < board.size(); i++) { // for each row in the board
            for (int j = 0; j < board[0].size(); j++) { // for each column in the board
                dfs(board, i, j, root, result); // call dfs
            }
        }
        return result; // return the result
    }

    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words) { // build a trie from the words
        TrieNode *root = new TrieNode(); // initialize the root node
        for (int j = 0; j < words.size(); j++) { // for each word in words
            string word = words[j]; // set word to the current word
            TrieNode *curr = root; // set curr to the root
            for (int i = 0; i < word.length(); i++) { // for each character in word
                char c = word[i] - 'a'; // set c to the current character
                if (curr->children[c] == nullptr) { // if curr->children[c] is nullptr
                    curr->children[c] = new TrieNode(); // set curr->children[c] to a new node
                }
                curr = curr->children[c]; // set curr to curr->children[c]
            }
            curr->word = word; // set curr->word to word
        }
        return root; // return the root
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) { // depth first search
        char c = board[i][j]; // set c to the current character
        if (c == '#' || !p->children[c - 'a']) return; // if c is '#' or p->children[c - 'a'] is nullptr, return
        p = p->children[c - 'a']; // set p to p->children[c - 'a']
        if (p->word.size() > 0) { // if p->word is not empty
            result.push_back(p->word); // push p->word to result
            p->word = ""; // set p->word to ""
        }

        board[i][j] = '#'; // set board[i][j] to '#'
        if (i > 0) dfs(board, i - 1, j, p, result); // call dfs on the left
        if (j > 0) dfs(board, i, j - 1, p, result); // call dfs on the top
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result); // call dfs on the right
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result); // call dfs on the bottom
        board[i][j] = c; // set board[i][j] to c
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> result = s.findWords(board, words);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
