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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head== nullptr) return nullptr;

        int cnt{1};
        auto left{head}, right{head};
        while(right->next != nullptr) {
            cnt++;
            right = right->next;
        }

        auto distance = cnt - k%cnt;
        if(distance==cnt)
            return head;

        for(auto i=0; i<distance-1; i++) {
            left=left->next;
        }
        auto res = left->next;
        left->next = nullptr;
        right->next = head;
        return res;
    }
};
