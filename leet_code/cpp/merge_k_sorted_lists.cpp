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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr; // create a pointer to the head of the list
        ListNode* p = nullptr; // create a pointer to the head of the list
        int min = 0; // initialize the minimum value
        int min_index = 0; // initialize the index of the minimum value
        int i = 0; // initialize the counter
        int j = 0; // initialize the counter
        int k = 0; // initialize the counter
        int n = lists.size(); // get the size of the vector
        while (i < n) { // loop through the vector
            if (lists[i] == nullptr) { // if the pointer is null, remove the pointer from the vector
                lists.erase(lists.begin() + i); // remove the pointer from the vector
                n--; // decrement the size of the vector
            }
            else {
                i++; // increment the counter
            }
        }
        while (lists.size() > 0) { // loop through the vector
            min = lists[0]->val; // set the minimum value to the first value in the vector
            min_index = 0; // set the index of the minimum value to 0
            for (j = 1; j < lists.size(); j++) { // loop through the vector
                if (lists[j]->val < min) { // if the value is less than the minimum value, set the minimum value to the value
                    min = lists[j]->val; // set the minimum value to the value
                    min_index = j; // set the index of the minimum value to the index
                }
            }
            if (head == nullptr) { // if the head of the list is null, set the head of the list to the minimum value
                head = lists[min_index]; // set the head of the list to the minimum value
                p = head; // set the pointer to the head of the list
            }
            else { // if the head of the list is not null, add the minimum value to the list
                p->next = lists[min_index]; // add the minimum value to the list
                p = p->next; // move the pointer to the next node
            }
            lists[min_index] = lists[min_index]->next; // move the pointer to the next node
            if (lists[min_index] == nullptr) { // if the pointer is null, remove the pointer from the vector
                lists.erase(lists.begin() + min_index); // remove the pointer from the vector
            }        
    }
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