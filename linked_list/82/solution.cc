#include <iostream>
#include <limits>

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
        ListNode newhead(std::numeric_limits<int>::min(), head);
        auto ptr = &newhead;

        while(ptr->next!= nullptr && ptr->next->next!= nullptr) {
            if(ptr->next->val == ptr->next->next->val) {
                auto p = ptr->next->next->next;
                while(p!= nullptr && ptr->next->val == p->val)
                    p = p->next;
                ptr->next = p;
            } else {
                ptr = ptr->next;
            }
        }

        return newhead.next;
    }
};
