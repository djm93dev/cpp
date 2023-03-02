#include <iostream>
#include <string>
#include <vector>
#include <queue>


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
    int maxDepth(TreeNode* root) {

        if (root == nullptr) { // if root is null, return 0
            return 0; // return 0
        }

        std::queue<TreeNode*> q; // create a queue
        q.push(root); // push the root into the queue
        int depth = 0; // set depth to 0

        while (!q.empty()) { // while the queue is not empty
            int size = q.size(); // get the size of the queue
            for (int i = 0; i < size; i++) { // for each element in the queue
                TreeNode* node = q.front(); // get the front of the queue
                q.pop(); // pop the front of the queue
                if (node->left != nullptr) { // if the left node is not null
                    q.push(node->left); // push the left node into the queue
                }
                if (node->right != nullptr) { // if the right node is not null
                    q.push(node->right); // push the right node into the queue
                }
            }
            depth++; // increment the depth
        }
        return depth; // return the depth
        
    }
};

int main() {
    Solution s;
    std::cout << s.maxDepth(nullptr) << std::endl;
    return 0;
}