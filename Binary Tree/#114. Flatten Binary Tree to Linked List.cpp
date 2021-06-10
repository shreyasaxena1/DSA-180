//TC -O(N) SC-O(1)
//https://youtu.be/zbe3R19mzO8 (Optimal)
//https://youtu.be/pCtXQ9XI7As (Rest)

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                TreeNode *prev = curr->left;
                while (prev->right)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};