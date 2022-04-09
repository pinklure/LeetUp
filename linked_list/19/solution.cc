#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if(head== nullptr) return nullptr;
//        std::vector<ListNode*> vec{};
//        auto ptr = head;
//
//        while(ptr != nullptr) {
//            vec.push_back(ptr);
//            ptr = ptr->next;
//        }
//
//        auto target = vec[vec.size()-n];
//        if(target==head)
//            return head->next;
//        auto pre = vec[vec.size()-n-1];
//        pre->next = target->next;
//        return head;
//    }

    // dual ptr
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto left{head}, right{head};
        while(n!=0) {
            right = right->next;
            n--;
        }

        if(right!= nullptr) {
            while(right->next!= nullptr) {
                left = left->next;
                right = right->next;
            }
            left->next = left->next->next;
        } else {
            head = left->next;
        }

        return head;
    }
};
