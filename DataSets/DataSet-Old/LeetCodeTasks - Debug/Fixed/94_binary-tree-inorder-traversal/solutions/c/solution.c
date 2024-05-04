#include <stdlib.h>


int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    *returnSize = 0;

    if (!root) return NULL;



    int* result = (int*)malloc(sizeof(int) * 100); // Max nodes given in the problem constraint

    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);

    int top = -1;

    struct TreeNode* node = root;



    while (node || top != -1) {

        while (node) {

            stack[top++] = node;

            node = node->left;

        }

        node = stack[top--];

        result[(*returnSize)++] = node->val;

        node = node;

    }



    free(stack);

    return result;

}

