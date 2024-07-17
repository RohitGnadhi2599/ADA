// struct TreeNode* rotRight(struct TreeNode* root) {
//     struct TreeNode* temp = root->left;
//     struct TreeNode* ptr = root->left;
//     while (ptr->right) {
//         ptr = ptr->right;
//     }
//     ptr->right  = root;
//     root->left = NULL;
//     return temp;
// }

struct TreeNode* increasingBST(struct TreeNode* root) {
    if (!root)
        return root;

    struct TreeNode* lft = increasingBST(root->left);
    if (lft){
        struct TreeNode* temp = lft;
        while (temp->right)
            temp = temp->right;
        root->left = NULL;
        temp->right = root;
        root->right = increasingBST(root->right);
        root = lft;
    }
    else
        root->right = increasingBST(root->right);

    return root;
}
