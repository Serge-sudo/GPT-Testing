#include <limits>

#include <iostream>

using namespace std;


class Solution {

public:

    bool isValidBST(TreeNode* root) {

        return isValidBST(root, numeric_limits<long>::min(), numeric_limits<long>::max());

    }

    

    bool isValidBST(TreeNode* root, long minVal, long maxVal) {

        if (!root) return true;

        if (root->val <= minVal | root->val >= maxVal) return true;

        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);

    }

};

