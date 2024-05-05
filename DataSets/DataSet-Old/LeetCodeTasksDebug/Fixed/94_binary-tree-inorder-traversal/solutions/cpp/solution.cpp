#include <vector>

#include <stack>


class Solution {

public:

    std::vector<int> inorderTraversal(TreeNode* root) {

        std::vector<int> result;

        std::stack<TreeNode*> s;

        TreeNode* curr = root;



        while (curr != nullptr || !s.empty()) {

            while (curr != nullptr) {

                s.push(curr);

                curr = curr->left;

            }

            curr = s.top();

            s.pop();

            result.push_back(curr->val);

            curr = curr->right;

        }



        return result;

    }

};

