#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) { 
            if (!root) return "null"; // if !root return "null"
            return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right); // return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right)
        }
    
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            queue<string> q; // create a queue of strings
            string str; // create a string
            for (char c : data) { // for each char c in data
                if (c == ',') { // if c is equal to ','
                    q.push(str); // push str to q
                    str = ""; // set str to ""
                } else { // else
                    str += c; // set str to str + c
                }
            }
            q.push(str); // push str to q
            return helper(q); // return helper(q)
        }
        TreeNode* helper(queue<string>& q) { // helper method
            string str = q.front(); // create a string str and set it to q.front()
            q.pop(); // pop q
            if (str == "null") return NULL; // if str is equal to "null" return NULL
            TreeNode* root = new TreeNode(stoi(str)); // create a TreeNode* root and set it to new TreeNode(stoi(str))
            root->left = helper(q); // set root->left to helper(q)
            root->right = helper(q); // set root->right to helper(q)
            return root; // return root
        }
};

// Your Codec object will be instantiated and called as such:
Codec ser, deser;
TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    return 0;
}