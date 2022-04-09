#include <iostream>
#include <vector>

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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_list{}, greater_list{};
        auto less_ptr{&less_list}, greater_ptr{&greater_list};
        auto ptr = head;
        while(ptr!= nullptr) {
            if(ptr->val<x) {
                less_ptr->next = ptr;
                less_ptr = less_ptr->next;
            } else {
                greater_ptr->next = ptr;
                greater_ptr = greater_ptr->next;
            }
//            printLinkedList(less_list.next);
//            printLinkedList(greater_list.next);
//            std::cout<<std::endl;
            ptr = ptr->next;

        }
        less_ptr->next = greater_list.next;
        greater_ptr->next= nullptr;

        return less_list.next;
    }
};

void printLinkedList(ListNode *head) {
    int cnt = 30;
    while(head!= nullptr && cnt>0) {
        std::cout<<head->val<<" ";
        head=head->next;
        cnt--;
    }
    std::cout<<"\n\n";
}

ListNode* generateLinkedList(std::vector<int> const& vec) {
    ListNode* ptr{};
    for(auto it=vec.rbegin(); it!=vec.rend(); it++) {
        ptr = new ListNode(*it, ptr);
    }
    return ptr;
}


int main() {
    Solution test;
    auto tmp = generateLinkedList({1,4,3,2,5,2});
    printLinkedList(tmp);

//    test.partition(tmp,3);

    printLinkedList(test.partition(tmp, 3));
}
