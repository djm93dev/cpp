#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) { // if root is null or root is equal to p or root is equal to q
            return root; // return root
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q); // set left to lowestCommonAncestor(root->left, p, q)
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // set right to lowestCommonAncestor(root->right, p, q)
        if (left == nullptr) { // if left is null
            return right; // return right
        }
        if (right == nullptr) { // if right is null
            return left; // return left
        }
        return root; // return root
        
    }
};

int main() {
    Solution s;
    return 0;
}

