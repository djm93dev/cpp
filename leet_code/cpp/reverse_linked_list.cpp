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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // initialize prev to nullptr
        ListNode* curr = head; // initialize curr to head
        while (curr != nullptr) { // while curr is not equal to nullptr
            ListNode* nextTemp = curr->next; // set nextTemp to the next element of curr
            curr->next = prev; // set the next element of curr to prev
            prev = curr; // set prev to curr
            curr = nextTemp; // set curr to nextTemp
        }
        return prev; // return prev

    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* reversed = s.reverseList(head);
    while (reversed != nullptr) {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }
    cout << endl;
    return 0;
}