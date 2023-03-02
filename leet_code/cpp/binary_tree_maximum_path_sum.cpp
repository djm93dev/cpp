#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN; // set the max sum to the lowest possible value
        max_gain(root, max_sum); // call the max gain function
        return max_sum;  // return the max sum
    }
    int max_gain(TreeNode* node, int& max_sum) { // function to find the max gain
        if (node == nullptr) { // if the node is null
            return 0; // return 0
        }
        int left_gain = max(max_gain(node->left, max_sum), 0); // set the left gain to the max of the max gain of the left node and 0
        int right_gain = max(max_gain(node->right, max_sum), 0); // set the right gain to the max of the max gain of the right node and 0
        int price_newpath = node->val + left_gain + right_gain; // set the price of the new path to the value of the node plus the left gain plus the right gain
        max_sum = max(max_sum, price_newpath); // set the max sum to the max of the max sum and the price of the new path
        return node->val + max(left_gain, right_gain); // return the value of the node plus the max of the left gain and the right gain
    }
};

int main() {
    Solution s;
    return 0;
}