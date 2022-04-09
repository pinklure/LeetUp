#include <iostream>
#include <stack>
#include <vector>


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
    std::vector<int> res{};
    void InOrder(TreeNode *root) {
        if(root== nullptr)
            return;
        InOrder(root->left);
        res.push_back(root->val);
        InOrder(root->right);
    }

//    vector<int> inorderTraversal(TreeNode *root) {
//        InOrder(root);
//        return res;
//    }
    vector<int> inorderTraversal(TreeNode *root) {
        std::stack<TreeNode*> ss{};
        std::vector<int> res{};
        ss.push(root);


        while(!ss.empty()) {
            while(ss.top()->left!= nullptr)
                ss.push(ss.top()->left);
            res.push_back(ss.top()->val);
            if(ss.top()->right != nullptr) {

            }
        }
    }
};