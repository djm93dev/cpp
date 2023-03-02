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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // initialize result vector
        if(root==NULL) return result; // if the root is NULL, return the result
        stack<TreeNode*> s1; // create a stack to store the nodes of each level
        stack<TreeNode*> s2; // create a stack to store the nodes of each level
        s1.push(root); // push the root into the stack
        while(!s1.empty() || !s2.empty()){ // while the stack is not empty
            vector<int> temp; // create a vector to store the values of each level
            while(!s1.empty()){ // while the stack is not empty
                TreeNode* node = s1.top(); // get the first node in the stack
                s1.pop(); // pop the first node in the stack
                temp.push_back(node->val); // push the value of the node into the level vector
                if(node->left!=NULL) s2.push(node->left); // if the left child of the node is not NULL, push it into the stack
                if(node->right!=NULL) s2.push(node->right); // if the right child of the node is not NULL, push it into the stack
            }
            if(!temp.empty()) result.push_back(temp); // if the level vector is not empty, push it into the result vector
            temp.clear(); // clear the level vector
            while(!s2.empty()){ // while the stack is not empty
                TreeNode* node = s2.top(); // get the first node in the stack
                s2.pop(); // pop the first node in the stack
                temp.push_back(node->val); // push the value of the node into the level vector
                if(node->right!=NULL) s1.push(node->right); // if the right child of the node is not NULL, push it into the stack
                if(node->left!=NULL) s1.push(node->left); // if the left child of the node is not NULL, push it into the stack
            }
            if(!temp.empty()) result.push_back(temp); // if the level vector is not empty, push it into the result vector
        }
        return result; // return the result
        
    }
};

int main() {
    Solution s;
    return 0;
}