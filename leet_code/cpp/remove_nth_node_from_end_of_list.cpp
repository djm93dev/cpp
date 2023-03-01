#include <iostream>

using namespace std;

//  * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head; // create a pointer to the head of the list
        ListNode* q = head; // create a pointer to the head of the list
        ListNode* r = head; // create a pointer to the head of the list
        int i = 0; // initialize the counter
        while (i < n) { // loop through the list until the counter reaches n
            q = q->next; // move the pointer to the next node
            i++; // increment the counter
        }
        if (q == nullptr) { // if the pointer reaches the end of the list, remove the head of the list
            head = head->next; // remove the head of the list
            return head; // return the new head of the list
        }
        while (q->next != nullptr) { // loop through the list until the pointer reaches the end of the list
            p = p->next; // move the pointer to the next node
            q = q->next; // move the pointer to the next node
        }
        r = p->next; // set the pointer to the node to be removed
        p->next = r->next; // remove the node
        return head; // return the head of the list
        
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    Solution s;
    ListNode* ans = s.removeNthFromEnd(head, 2);
    while (ans != nullptr) {
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}