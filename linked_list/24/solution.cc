#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode *head);

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;


        auto revertPointer = [](ListNode* left) {
            if(left == nullptr || left->next == nullptr)
                return left;
            auto right = left->next;
            left->next = right->next;
            right->next = left;
            return right;
        };

        auto n = revertPointer(head);
        head = n;
//        printLinkedList(head);

        n = n->next;

        while(true) {
            n->next = revertPointer(n->next);
//            printLinkedList(head);

            if(n->next == nullptr || n->next->next == nullptr)
                break;
            n = n->next->next;
        }

        return head;
    }
};

void printLinkedList(ListNode *head) {
    while(head!= nullptr) {
        std::cout<<head->val<<" ";
        head=head->next;
    }
    std::cout<<"\n\n";
}

int main() {
    ListNode d(4);
    ListNode c(3, &d);
    ListNode b(2, &c);
    ListNode a(1, &b);

    printLinkedList(&a);

    Solution test;
    auto res = test.swapPairs(&a);


    printLinkedList(res);
}
