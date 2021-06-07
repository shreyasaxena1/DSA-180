//TC - O(N)  SC -O(H)
//Solved at gfg
//Recursive

void leftViewUtil(Node *root, int level, int *max_level, vector<int> &ans);
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int max_level = 0;
    leftViewUtil(root, 1, &max_level, ans);
    return ans;
}

//Kind of preorder
void leftViewUtil(Node *root, int level, int *max_level, vector<int> &ans)
{
    if (root == NULL)
        return;

    //Node
    if (*max_level < level)
    {
        ans.push_back(root->data);
        *max_level = level;
    }

    //Left

    leftViewUtil(root->left, level + 1, max_level, ans);

    //Right

    leftViewUtil(root->right, level + 1, max_level, ans);
}