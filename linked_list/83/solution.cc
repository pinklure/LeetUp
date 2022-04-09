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
    ListNode* deleteDuplicates(ListNode* head) {
        auto ptr = head;

        while(ptr!= nullptr) {
            if(ptr->next != nullptr && ptr->val == ptr->next->val) {
                auto p = ptr->next->next;
                while(p!= nullptr && p->val==ptr->val)
                    p = p->next;
                ptr->next = p;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};
