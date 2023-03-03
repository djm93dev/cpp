#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Trie {
    struct TrieNode 
    {
        map<char, TrieNode*>child_table; // map from char to TrieNode*
        int end; // 1 if this node is the end of a word, 0 otherwise
        TrieNode(): end(0) {} // constructor
    };
        
public:
    Trie() {
        root = new TrieNode(); // initialize root to a new TrieNode
    }

    // Inserts a word into the trie.
    void insert(string s) { // insert a word into the trie
        TrieNode *curr = root; // set curr to root
        for (int i = 0; i < s.size(); i++) // for each character in s
        {
            if (curr->child_table.count(s[i]) == 0) // if curr->child_table does not contain s[i]
                curr->child_table[s[i]] = new TrieNode(); // add s[i] to curr->child_table and set its value to a new TrieNode
                
            curr = curr->child_table[s[i]]; // set curr to curr->child_table[s[i]]
        }
        curr->end = 1; // set curr->end to 1
    }

    // Returns if the word is in the trie.
    bool search(string key) { // search for a word in the trie
        return find(key, 1); // call find with exact_match set to 1
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) { // search for a prefix in the trie
        return find(prefix, 0); // call find with exact_match set to 0
    }

private:
    TrieNode* root; // root of the trie
    bool find(string s, int exact_match) // search for a word or prefix in the trie
    {
        TrieNode *curr = root; // set curr to root
        for (int i = 0; i < s.size(); i++) // for each character in s
        {
            if (curr->child_table.count(s[i]) == 0) // if curr->child_table does not contain s[i]
                return false; // return false
            else // otherwise
                curr = curr->child_table[s[i]]; // set curr to curr->child_table[s[i]]
        }
        
        if (exact_match) // if exact_match is true
            return (curr->end) ? true : false; // return true if curr->end is true, false otherwise
        else // otherwise
            return true; // return true
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");   
    cout << trie.search("app") << endl;     // returns true
    return 0;
}
