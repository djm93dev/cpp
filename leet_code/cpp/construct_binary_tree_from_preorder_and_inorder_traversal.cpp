#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) { // if the preorder vector is empty
            return nullptr; // return null
        }
        TreeNode* root = new TreeNode(preorder[0]); // create a new node with the first element of the preorder vector
        stack<TreeNode*> s; // create a stack
        s.push(root); // push the root into the stack
        int inorderIndex = 0; // set the inorder index to 0
        for (int i = 1; i < preorder.size(); i++) { // for each element in the preorder vector
            int preorderVal = preorder[i]; // get the value of the current element
            TreeNode* node = s.top(); // get the top of the stack
            if (node->val != inorder[inorderIndex]) { // if the top of the stack is not equal to the current element of the inorder vector
                node->left = new TreeNode(preorderVal); // set the left node to the current element of the preorder vector
                s.push(node->left); // push the left node into the stack
            }
            else {
                while (!s.empty() && s.top()->val == inorder[inorderIndex]) { // while the stack is not empty and the top of the stack is equal to the current element of the inorder vector
                    node = s.top(); // get the top of the stack
                    s.pop(); // pop the top of the stack
                    inorderIndex++; // increment the inorder index
                }
                node->right = new TreeNode(preorderVal); // set the right node to the current element of the preorder vector
                s.push(node->right); // push the right node into the stack
            }
        }
        return root; // return the root
        
        
    }
};

int main() {
    Solution s;
    return 0;
}