#include <algorithm>

#include <stack>

class Solution {

public:

    void recoverTree(TreeNode* root) {

        TreeNode *first = nullptr, *second = nullptr;

        TreeNode *prev = nullptr;

        std::stack<TreeNode*> stack;

        

        while (root || !stack.empty()) {

            while (root) {

                stack.push(root);

                root = root->left;

            }

            root = stack.top();

            stack.pop();

            if (prev && prev->val >= root->val) {

                if (!first) first = prev;

                second = root;

            }

            prev = root;

            root = root->right;

        }

        

        std::swap(first->val, second->val);

    }

};

