class Solution
{
public:
    //Function to find the height of a binary tree.
    int height(struct Node *root)
    {
        if (root == NULL)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }
};