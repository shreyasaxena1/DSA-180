//Create image of BT - Same
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {

        invertTreeUtil(root);

        return root;
    }
    void invertTreeUtil(TreeNode *root)
    {
        if (!root)
            return;

        TreeNode *temp = new TreeNode();
        invertTreeUtil(root->left);
        invertTreeUtil(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
};