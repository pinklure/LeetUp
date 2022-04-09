#include <iostream>

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
        if(l1== nullptr || l2== nullptr) return nullptr;

        auto ptr1 = l1, ptr2 = l2;

        ptr1->val += ptr2->val;
        while(ptr1->next != nullptr && ptr2->next != nullptr) {
            ptr1->next->val += ptr2->next->val;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if(ptr1->next == nullptr) {
            ptr1->next = ptr2->next;
        }

        ptr1 = l1;

        while(ptr1->next != nullptr) {
            ptr1->next->val += ptr1->val/10;
            ptr1->val %= 10;
            ptr1 = ptr1->next;
        }
        if(ptr1->val>=10) {
            ptr1->next = new ListNode(ptr1->val/10);
            ptr1->val %= 10;
        }
        return l1;
    }
};
