#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0); // create new ListNode
        ListNode* curr = head; // initialize curr to head
        while (list1 != nullptr && list2 != nullptr) { // while list1 and list2 are not equal to nullptr
            if (list1->val < list2->val) { // if list1->val is less than list2->val
                curr->next = list1; // set curr->next to list1
                list1 = list1->next; // set list1 to list1->next
            }
            else {
                curr->next = list2; // set curr->next to list2
                list2 = list2->next; // set list2 to list2->next
            }
            curr = curr->next; // set curr to curr->next
        }
        if (list1 != nullptr) { // if list1 is not equal to nullptr
            curr->next = list1; // set curr->next to list1
        }
        if (list2 != nullptr) { // if list2 is not equal to nullptr
            curr->next = list2; // set curr->next to list2
        }
        return head->next; // return head->next
        
    }
};

int main()
{
    Solution s;
}
