//V - Kashis M.
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;

        return a->val == b->val &&
               isMirror(a->left, b->right) &&
               isMirror(a->right, b->left);
    }
};