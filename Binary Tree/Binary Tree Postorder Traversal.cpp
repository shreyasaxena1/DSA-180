//Solved at interviewbit
//Need two stacks! TC - O(N) SC -O(N)

vector<int> Solution::postorderTraversal(TreeNode *root)
{

    vector<int> ans;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    TreeNode *temp = new TreeNode(0);
    s1.push(root);

    while (!s1.empty())
    {
        temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    while (!s2.empty())
    {
        TreeNode *top = s2.top();
        ans.push_back(top->val);
        s2.pop();
    }
    return ans;
}
