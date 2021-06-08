class Solution
{
public:
    int postIndex;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        postIndex = postorder.size() - 1;
        return buildTreeUtil(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int ins, int ine)
    {

        if (ins > ine)
            return NULL;

        TreeNode *root = new TreeNode(postorder[postIndex]);

        int inIndex;
        for (int i = ins; i <= ine; i++)
        {
            if (inorder[i] == postorder[postIndex])
            {
                inIndex = i;
                break;
            }
        }
        postIndex--;

        root->right = buildTreeUtil(inorder, postorder, inIndex + 1, ine);
        root->left = buildTreeUtil(inorder, postorder, ins, inIndex - 1);

        return root;
    }
};