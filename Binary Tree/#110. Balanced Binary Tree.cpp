//TC -O(N)

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (isBalancedUtil(root) == -1)
            return false;
        return true;
    }

    int isBalancedUtil(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = isBalancedUtil(root->left);
        if (lh == -1)
            return -1;

        int rh = isBalancedUtil(root->right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;

        return max(lh, rh) + 1;
    }
};