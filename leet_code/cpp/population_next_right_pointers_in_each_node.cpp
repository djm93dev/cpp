#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) { // if the root is null
            return nullptr; // return null
        }
        queue<Node*> q; // create a queue
        q.push(root); // push the root into the queue
        while (!q.empty()) { // while the queue is not empty
            int size = q.size(); // get the size of the queue
            for (int i = 0; i < size; i++) { // for each element in the queue
                Node* node = q.front(); // get the front of the queue
                q.pop(); // pop the front of the queue
                if (i < size - 1) { // if the current element is not the last element
                    node->next = q.front(); // set the next node to the front of the queue
                }
                if (node->left != nullptr) { // if the left node is not null
                    q.push(node->left); // push the left node into the queue
                }
                if (node->right != nullptr) { // if the right node is not null
                    q.push(node->right); // push the right node into the queue
                }
            }
        }
        return root; // return the root
        
    }
};

int main() {
    Solution s;
    return 0;
}