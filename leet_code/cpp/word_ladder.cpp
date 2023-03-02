#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q; // create a queue
        q.push(beginWord); // push the begin word onto the queue
        int level = 0; // set the level to 0
        while (!q.empty()) { // while the queue is not empty
            int size = q.size(); // set the size to the size of the queue
            level++; // increment the level
            for (int i = 0; i < size; i++) { // for the size of the queue
                string word = q.front(); // set the word to the front of the queue
                q.pop(); // pop the front of the queue
                if (word == endWord) { // if the word is equal to the end word
                    return level; // return the level
                }
                for (int j = 0; j < wordList.size(); j++) { // for the size of the word list
                    if (wordList[j] == "") { // if the word list at j is equal to ""
                        continue; // continue
                    }
                    int diff = 0; // set the diff to 0
                    for (int k = 0; k < word.size(); k++) { // for the size of the word
                        if (word[k] != wordList[j][k]) { // if the word at k is not equal to the word list at j at k
                            diff++; // increment the diff
                        }
                    }
                    if (diff == 1) { // if the diff is equal to 1
                        q.push(wordList[j]); // push the word list at j onto the queue
                        wordList[j] = ""; // set the word list at j to ""
                    }
                }
            }
        }
        return 0; // return 0
        
    }
};

int main () {
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    s.ladderLength(beginWord, endWord, wordList);
    return 0;
}