#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;


//  Definition for a binary tree node.
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st; // initialize a stack
        TreeNode* curr = root; // set curr to root
        while (curr != nullptr || !st.empty()) { // while curr is not null or the stack is not empty
            while (curr != nullptr) { // while curr is not null
                st.push(curr); // push curr to the stack
                curr = curr->left; // set curr to curr->left
            }
            curr = st.top(); // set curr to the top of the stack
            st.pop(); // pop the top of the stack
            if (--k == 0) { // if k is equal to 0
                return curr->val; // return curr->val
            }
            curr = curr->right; // set curr to curr->right
        }
        return -1; // return -1
        
    }
};

int main() {
    Solution s;
    return 0;
}