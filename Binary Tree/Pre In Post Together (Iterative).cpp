//Sumit sir pepcoding approach
//TC-O(N) SC-O(N) if we use vectors to store result of each traversal

void iterativePreorderPostorder(TreeNode *root)
{

    if (!root)
        return;
    stack<pair<TreeNode *, int>> s; // {node, state}
    s.push({root, 1});
    string preTraversal, posTraversal, inorderTraversal;
    while (!s.empty())
    {
        auto state = s.top().second;
        auto node = s.top().first;
        if (state == 1)
        {
            preTraversal += to_string(node->val);
            s.top().second++;
            if (node->left)
                s.push({node->left, 1});
        }
        else if (state == 2)
        {
            inorderTraversal += to_string(node->val);
            s.top().second++;
            if (node->right)
                s.push({node->right, 1});
        }
        else
        {
            posTraversal += to_string(node->val);
            s.pop();
        }
    }
    cout << preTraversal << endl
         << inorderTraversal << endl
         << posTraversal << endl;
}