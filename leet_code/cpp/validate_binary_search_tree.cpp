#include <iostream>
#include <string>
#include <vector>
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s; // create a stack to store the nodes of the binary tree
        TreeNode* curr = root; // create a pointer to the current node
        TreeNode* prev = nullptr; // create a pointer to the previous node
        while (curr != nullptr || !s.empty()) { // while the current node is not null or the stack is not empty
            while (curr != nullptr) { // while the current node is not null
                s.push(curr); // push the current node into the stack
                curr = curr->left; // move the current node to the left child
            }
            curr = s.top(); // get the top element of the stack
            s.pop(); // pop the top element of the stack
            if (prev != nullptr && curr->val <= prev->val) { // if the current node is not null and the value of the current node is less than or equal to the value of the previous node
                return false; // return false
            }
            prev = curr; // set the previous node to the current node
            curr = curr->right; // move the current node to the right child
        }
        return true; // return true
        
    }
};

int main() {
    Solution s;
    return 0;
}