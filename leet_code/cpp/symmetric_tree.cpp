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
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true; // if the root is NULL, return true
        
        return isSymmetricTest(root->left,root->right); // call the isSymmetricTest function to compare the left subtree with the right subtree
    }
    
    bool isSymmetricTest(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) //both of them are NULL
            return true;  //return true
        
        else if(p == NULL || q == NULL) // one of them is NULL
            return false; //return false
        
        else if(p->val!=q->val)  //both of them are not NULL, but their values are not equal
            return false; //return false
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left); // call the isSymmetricTest function to compare the left subtree with the right subtree and the right subtree with the left subtree
    }
};

int main() {
    Solution s;
    return 0;
}