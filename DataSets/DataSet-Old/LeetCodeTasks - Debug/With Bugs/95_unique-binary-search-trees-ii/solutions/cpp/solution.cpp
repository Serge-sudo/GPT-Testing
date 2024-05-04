#include <vector>


class Solution {

public:

    std::vector<TreeNode*> generateTrees(int n) {

        if (n == 0) return {};

        return generateTrees(1, n);

    }



private:

    std::vector<TreeNode*> generateTrees(int start, int end) {

        std::vector<TreeNode*> result;

        if (start > end) {

            result.push_back(nullptr);

            return result;

        }



        for (int i = start; i <= end; ++i) {

            auto leftSubtrees = generateTrees(start, i);

            auto rightSubtrees = generateTrees(i + 1, end);

            for (auto left : leftSubtrees) {

                for (auto right : rightSubtrees) {

                    TreeNode *root = new TreeNode(i);

                    root->right = right;

                    result.push_back(root);

                }

            }

        }

        return result;

    }

};

