class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return NULL;

        if (val > root->val)
            return searchBST(root->right, val);

        if (val < root->val)
            return searchBST(root->left, val);
        return root;
    }
};