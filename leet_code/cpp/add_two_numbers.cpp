#include <iostream>


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0); // create a new node
        ListNode* curr = head; // set the current node to the head
        while (l1 != nullptr && l2 !=nullptr){ // while both lists are not empty
            curr->next = new ListNode(l1->val + l2->val); // add the values of the nodes and create a new node
            curr = curr->next; // set the current node to the next node
            l1 = l1->next; // set the first list to the next node
            l2 = l2->next; // set the second list to the next node

        }

        while (l1 != nullptr){ // if the first list is not empty
            curr->next = new ListNode(l1->val); // create a new node with the value of the first list
            curr = curr->next; // set the current node to the next node
            l1 = l1->next; // set the first list to the next node
        }

        while (l2 != nullptr){ // if the second list is not empty
            curr->next = new ListNode(l2->val); // create a new node with the value of the second list
            curr = curr->next; // set the current node to the next node
            l2 = l2->next; // set the second list to the next node
        }

        curr = head->next; // set the current node to the next node

        while (curr != nullptr){ // while the current node is not empty
            if (curr->val > 9){ // if the value of the current node is greater than 9
                curr->val -= 10; // subtract 10 from the value
                if (curr->next != nullptr) // if the next node is not empty
                    curr->next->val += 1; // add 1 to the value of the next node
                else // if the next node is empty
                    curr->next = new ListNode(1); // create a new node with the value of 1
            }
            curr = curr->next; // set the current node to the next node
        }

        return head->next; // return the next node
    }
};

int main()
{
    Solution s;
}