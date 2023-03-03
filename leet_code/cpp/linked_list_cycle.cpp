#include <iostream>
#include <vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) { // If the head is null.
            return false; // Return false.
        }
        ListNode* slow = head; // Create a slow pointer.
        ListNode* fast = head->next; // Create a fast pointer.
        while (slow != fast) { // While the slow pointer is not equal to the fast pointer.
            if (fast == NULL || fast->next == NULL) { // If the fast pointer is null or the next element of the fast pointer is null.
                return false; // Return false.
            }
            slow = slow->next; // Move the slow pointer to the next element.
            fast = fast->next->next; // Move the fast pointer to the next next element.
        }
        return true; // Return true.
        
    }
};

int main()
{
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    Solution s;
    cout << s.hasCycle(head) << endl;
    return 0;
}