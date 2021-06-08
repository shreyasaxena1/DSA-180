//TC - O(N) SC-O(H)

int isSumProperty(Node *root)
{

    if (root == NULL || root->left == NULL && root->right == NULL)
        return 1;

    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;

    return (sum == root->data && isSumProperty(root->left) && isSumProperty(root->right));
}