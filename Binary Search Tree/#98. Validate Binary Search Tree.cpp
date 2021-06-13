//Kashis M. explained
//TC - O(N) SC -O(H)

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isBSTUtil(root, LONG_MIN, LONG_MAX);
    }
    bool isBSTUtil(TreeNode *root, long int min, long int max)
    {
        if (root == NULL)
            return true;

        if (root->val < min || root->val > max)
            return false;
        if (min > max)
            return false;
        return isBSTUtil(root->left, min, (long int)root->val - 1) &&
               isBSTUtil(root->right, (long int)root->val + 1, max);
    }
};