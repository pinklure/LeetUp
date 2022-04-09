#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* PreOrder(TreeNode* node) {
        if(node== nullptr)
            return node;
        PreOrder(node->left);
        PreOrder(node->right);
        if(node->left!= nullptr) {
            if(node->right!= nullptr) {
                auto mostRight = node->left;
                while(mostRight->right!= nullptr)
                    mostRight = mostRight->right;
                mostRight->right = node->right;
            }

            node->right = node->left;
            node->left = nullptr;
        }
        return node;
    }

    void flatten(TreeNode* root) {
        PreOrder(root);
    }
};
