//Solved at gfg
//TC - O(N) SC - O(N)

class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        int max_level = 0;
        rightViewUtil(root, 1, &max_level, ans);
        return ans;
    }

    void rightViewUtil(Node *root, int level, int *max_level, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (*max_level < level)
        {
            ans.push_back(root->data);
            *max_level = level;
        }

        rightViewUtil(root->right, level + 1, max_level, ans);
        rightViewUtil(root->left, level + 1, max_level, ans);
    }
};