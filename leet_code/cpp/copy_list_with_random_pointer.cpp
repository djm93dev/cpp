#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL; // If the head is NULL, then return NULL.
        Node* curr = head; // Create a pointer to the head.
        while (curr != NULL) { // While the pointer is not NULL.
            Node* temp = curr->next; // Create a pointer to the next node.
            curr->next = new Node(curr->val); // Create a new node with the value of the current node.
            curr->next->next = temp; // Set the next node of the new node to the pointer to the next node.
            curr = temp; // Set the current node to the pointer to the next node.
        }
        curr = head; // Set the current node to the head.
        while (curr != NULL) { // While the current node is not NULL.
            if (curr->random != NULL) { // If the random pointer of the current node is not NULL.
                curr->next->random = curr->random->next; // Set the random pointer of the next node to the next node of the random pointer of the current node.
            }
            curr = curr->next->next; // Set the current node to the next node of the next node.
        }
        curr = head; // Set the current node to the head.
        Node* copy = head->next; // Create a pointer to the next node of the head.
        Node* copyHead = copy; // Create a pointer to the copy of the head.
        while (curr != NULL) { // While the current node is not NULL.
            curr->next = curr->next->next; // Set the next node of the current node to the next node of the next node.
            if (copy->next != NULL) { // If the next node of the copy is not NULL.
                copy->next = copy->next->next; // Set the next node of the copy to the next node of the next node.
            }
            curr = curr->next; // Set the current node to the next node.
            copy = copy->next; // Set the copy to the next node.
        }
        return copyHead; // Return the copy of the head.
        
    }
};


int main()
{
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    Solution s;
    Node* copy = s.copyRandomList(head);
    while (copy != NULL) {
        cout << copy->val << endl;
        copy = copy->next;
    }
    return 0;
}