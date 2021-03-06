//TC - O(N)  SC-O(N)

vector<int> preOrder(Node *root)
{
    vector<int> v;
    stack<Node *> s;

    s.push(root);

    while (!s.empty())
    {
        Node *temp = s.top();
        v.push_back(temp->data);
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    return v;
}