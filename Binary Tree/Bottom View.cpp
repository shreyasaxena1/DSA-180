vector<int> bottomView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<pair<Node *, int>> q;
    map<int, int> m;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();

        Node *temp = p.first;
        int hd = p.second;

        m[hd] = temp->data;

        if (temp->left)
            q.push(make_pair(temp->left, hd - 1));

        if (temp->right)
            q.push(make_pair(temp->right, hd + 1));
    }

    for (auto i = m.begin(); i != m.end(); i++)
        ans.push_back(i->second);

    return ans;
}