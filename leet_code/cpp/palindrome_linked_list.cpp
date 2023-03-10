#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { // if head is null or head->next is null
            return true; // return true
        }
        ListNode* slow = head; // set slow to head
        ListNode* fast = head; // set fast to head
        while (fast != nullptr && fast->next != nullptr) { // while fast is not null and fast->next is not null
            slow = slow->next; // set slow to slow->next
            fast = fast->next->next; // set fast to fast->next->next
        }
        ListNode* prev = nullptr; // set prev to null
        ListNode* curr = slow; // set curr to slow
        ListNode* next = nullptr; // set next to null
        while (curr != nullptr) { // while curr is not null
            next = curr->next; // set next to curr->next
            curr->next = prev; // set curr->next to prev
            prev = curr; // set prev to curr
            curr = next; // set curr to next
        }
        ListNode* left = head; // set left to head
        ListNode* right = prev; // set right to prev
        while (right != nullptr) { // while right is not null
            if (left->val != right->val) { // if left->val is not equal to right->val
                return false; // return false
            }
            left = left->next; // set left to left->next
            right = right->next; // set right to right->next
        }
        return true; // return true
        
    }
};

int main() {
    Solution s;
    return 0;
}