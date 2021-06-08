class Solution
{
public:
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return diameter - 1;
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if (diameter < 1 + lh + rh)
        {
            diameter = 1 + lh + rh;
        }

        return 1 + (lh > rh ? lh : rh);
    }
};