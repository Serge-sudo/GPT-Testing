#include <stdlib.h>


struct TreeNode* cloneTree(struct TreeNode* root) {
    if (!root) return NULL;

    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = root->val;
    newNode->left = cloneTree(root->left);
    newNode->right = cloneTree(root->right);

    return newNode;
}

struct TreeNode** generateTreesHelper(int start, int end, int* returnSize) {
    if (start > end) {
        *returnSize = 1;
        struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        result[0] = NULL;
        return result;
    }

    struct TreeNode** result = NULL;
    *returnSize = 0;

    for (int i = start; i <= end; i++) {
        int leftSize, rightSize;
        struct TreeNode** leftSubtrees = generateTreesHelper(start, i - 1, &leftSize);
        struct TreeNode** rightSubtrees = generateTreesHelper(i + 1, end, &rightSize);

        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = cloneTree(leftSubtrees[j]);
                root->right = cloneTree(rightSubtrees[k]);

                result = (struct TreeNode**)realloc(result, (*returnSize + 1) * sizeof(struct TreeNode*));
                result[*returnSize] = root;
                (*returnSize)++;
            }
        }

        free(leftSubtrees);
        free(rightSubtrees);
    }

    return result;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesHelper(1, n, returnSize);
}
