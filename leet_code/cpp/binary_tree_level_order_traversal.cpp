#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // create a vector to store the result
        if(root==NULL) return result; // if the root is NULL, return the result
        vector<int> level; // create a vector to store the values of each level
        queue<TreeNode*> q; // create a queue to store the nodes of each level
        q.push(root); // push the root into the queue
        q.push(NULL); // push a NULL into the queue to indicate the end of the first level
        while(!q.empty()){ // while the queue is not empty
            TreeNode* node = q.front(); // get the first node in the queue
            q.pop(); // pop the first node in the queue
            if(node==NULL){ // if the node is NULL
                result.push_back(level); // push the level vector into the result vector
                level.clear(); // clear the level vector
                if(!q.empty()) q.push(NULL); // if the queue is not empty, push a NULL into the queue to indicate the end of the next level
            }
            else{
                level.push_back(node->val); // push the value of the node into the level vector
                if(node->left!=NULL) q.push(node->left); // if the left child of the node is not NULL, push it into the queue
                if(node->right!=NULL) q.push(node->right); // if the right child of the node is not NULL, push it into the queue
            }
        }
        return result; // return the result
        
    }
};

int main() {
    Solution s;
    return 0;
}