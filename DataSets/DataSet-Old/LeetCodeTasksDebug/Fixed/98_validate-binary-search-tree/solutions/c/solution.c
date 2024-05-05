#include <stdbool.h>

#include <limits.h>



bool isBSTHelper(struct TreeNode* node, long min, long max) {

    if (node == NULL)

        return true;

    if (node->val <= min || node->val >= max)

        return false;

    return isBSTHelper(node->left, min, node->val) && isBSTHelper(node->right, node->val, max);

}



bool isValidBST(struct TreeNode* root) {

    return isBSTHelper(root, LONG_MIN, LONG_MAX);

}

