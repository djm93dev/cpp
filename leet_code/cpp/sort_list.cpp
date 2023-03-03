#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) { 
        if (head == nullptr || head->next == nullptr) { // If the list is empty or has only one element.
            return head; // Return the list.
        }
        ListNode* slow = head; // Set the slow pointer to the head of the list.
        ListNode* fast = head->next; // Set the fast pointer to the second element of the list.
        while (fast != nullptr && fast->next != nullptr) { // While the fast pointer is not at the end of the list.
            slow = slow->next; // Move the slow pointer to the next element.
            fast = fast->next->next; // Move the fast pointer to the next element.
        }
        ListNode* mid = slow->next; // Set the mid pointer to the next element of the slow pointer.
        slow->next = nullptr; // Set the next element of the slow pointer to null.
        ListNode* left = sortList(head); // Sort the left half of the list.
        ListNode* right = sortList(mid); // Sort the right half of the list.
        ListNode* h = new ListNode(0); // Create a new list node.
        ListNode* res = h; // Set the result pointer to the new list node.
        while (left != nullptr && right != nullptr) { // While the left and right pointers are not null.
            if (left->val < right->val) { // If the left pointer is less than the right pointer.
                h->next = left; // Set the next element of the result pointer to the left pointer.
                left = left->next; // Move the left pointer to the next element.
            } else {
                h->next = right; // Set the next element of the result pointer to the right pointer.
                right = right->next; // Move the right pointer to the next element.
            }
            h = h->next; // Move the result pointer to the next element.
        }
        h->next = left != nullptr ? left : right; // Set the next element of the result pointer to the left or right pointer.
        return res->next; // Return the next element of the result pointer.
        
    }
};

int main() {
    Solution s;
    return 0;
}