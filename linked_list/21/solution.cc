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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1== nullptr) return list2;
        if(list2== nullptr) return list1;

        auto ptr1{list1->val<=list2->val?list1 : list2},
             ptr2{ptr1==list1? list2 : list1};
        auto res = ptr1;

        while(ptr1->next != nullptr && ptr2 != nullptr) {
            if(ptr1->next->val > ptr2->val) {
                auto start = ptr2;
                auto end = ptr2;
                while( end->next != nullptr && ptr1->next->val > end->next->val) {
                    end = end->next;
                }
                ptr2 = end->next;
                end->next = ptr1->next;
                ptr1->next = start;
                ptr1 = end;
            } else {
                ptr1 = ptr1->next;
            }
        }

        if(ptr1->next == nullptr)
            ptr1->next = ptr2;

        return res;
    }
};
