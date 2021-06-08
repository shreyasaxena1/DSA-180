vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    stack<int> s;
    q.push(root);

    bool reverse = false; //if start from left of root

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (reverse)
            {
                s.push(temp->data);
            }
            else
            {
                ans.push_back(temp->data);
            }

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        if (reverse)
        {
            while (!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
        }
        reverse = !reverse;
    }
    return ans;
}
