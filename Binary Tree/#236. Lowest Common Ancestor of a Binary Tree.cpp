class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        //case 1
        if (root == p || root == q)
            return root;

        TreeNode *lcaL = lowestCommonAncestor(root->left, p, q);
        TreeNode *lcaR = lowestCommonAncestor(root->right, p, q);

        //case 2
        if (lcaL && lcaR)
            return root;

        //case 3 & 4

        if (lcaL)
            return lcaL;
        else
            return lcaR;
    }
};