#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA; // Create two pointers to iterate through list A.
        ListNode *pB = headB; // Create two pointers to iterate through list B.
        while (pA != pB) { // Iterate through both lists until the pointers are equal.
            pA = pA == NULL ? headB : pA->next; // If the pointer is NULL, set it to the head of the other list.
            pB = pB == NULL ? headA : pB->next; // If the pointer is NULL, set it to the head of the other list.
        }
        return pA; // Return the pointer.
        
    }
};

int main()
{
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    Solution s;
    cout << s.getIntersectionNode(headA, headB)->val << endl;
    return 0;
}