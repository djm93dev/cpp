#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) { // if head is nullptr
            return nullptr; // return nullptr
        }
        ListNode* odd = head; // set odd to head
        ListNode* even = head->next; // set even to head->next
        ListNode* evenHead = even; // set evenHead to even
        while (even != nullptr && even->next != nullptr) { // while even is not nullptr and even->next is not nullptr
            odd->next = even->next; // set odd->next to even->next
            odd = odd->next; // set odd to odd->next
            even->next = odd->next; // set even->next to odd->next
            even = even->next; // set even to even->next
        }
        odd->next = evenHead; // set odd->next to evenHead
        return head; // return head
        
    }
};

int main() {
    Solution s;
    return 0;
}