/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     struct TreeNode *left;

 *     struct TreeNode *right;

 * };

 */



struct TreeNode* prev;

struct TreeNode* first;

struct TreeNode* second;



void inorderTraversal(struct TreeNode* root) {

    if (root == NULL) return;

    

    inorderTraversal(root->left);

    

    if (prev != NULL && prev->val >= root->val) {

        if (first == NULL) {

            first = prev;

        }

        second = root;

    }

    

    prev = root;

    

    inorderTraversal(root->right);

}



void recoverTree(struct TreeNode* root) {

    prev = NULL;

    first = NULL;

    second = NULL;

    

    inorderTraversal(root);

    

    int temp = first->val;

    first->val = second->val;

    second->val = temp;

}

