#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


//  * Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; // create a vector to store the inorder traversal of the binary tree
        stack<TreeNode*> s; // create a stack to store the nodes of the binary tree
        TreeNode* curr = root; // create a pointer to the current node
        while (curr != nullptr || !s.empty()) { // while the current node is not null or the stack is not empty
            while (curr != nullptr) { // while the current node is not null
                s.push(curr); // push the current node into the stack
                curr = curr->left; // move the current node to the left child
            }
            curr = s.top(); // get the top element of the stack
            s.pop(); // pop the top element of the stack
            ans.push_back(curr->val); // push the value of the current node into the vector
            curr = curr->right; // move the current node to the right child
        }
        return ans; // return the inorder traversal of the binary tree
        
    }
};

int main() {
    Solution s;
    return 0;
}