#include <iostream>
#include <vector>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
//    ListNode* reverseList(ListNode* head) {
//        auto ptr{head};
//        std::stack<ListNode*> ss{};
//        while(ptr!= nullptr) {
//            ss.push(ptr);
//            ptr = ptr->next;
//        }
//
//        ListNode newhead{};
//        ptr = &newhead;
//
//        while(!ss.empty()) {
//            ptr->next = ss.top();
//            ptr = ptr->next;
//            ss.pop();
//        }
//        ptr->next = nullptr;
//        return newhead.next;
//    }
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto left{head}, right{head->next};
        while(right!= nullptr) {
            auto tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }

        head->next = nullptr;
        return left;
    }
};
