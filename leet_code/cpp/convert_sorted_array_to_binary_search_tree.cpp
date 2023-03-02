#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helperFunction(nums, 0, nums.size() - 1); // call helper function
    }
    TreeNode* helperFunction(vector<int>& nums, int left, int right) { // helper function
        if (left > right) { // if left is greater than right
            return nullptr; // return null
        }
        int mid = (left + right) / 2; // get the mid
        TreeNode* root = new TreeNode(nums[mid]); // create a new node
        root->left = helperFunction(nums, left, mid - 1); // set the left node
        root->right = helperFunction(nums, mid + 1, right); // set the right node
        return root; // return the root
    }
};

int main() {
    Solution s;
    return 0;
}