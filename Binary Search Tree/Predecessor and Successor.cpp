void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;
    //case 1
    if (key == root->key)
    {
        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }
        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return; // if for pre left is null so we take the value getting from the later if cndn
    }
    //case 2
    if (key < root->key)
    {
        suc = root; // succ is greater in value than key 0
        findPreSuc(root->left, pre, suc, key);
    }
    //case 3
    else
    {
        pre = root; // prev is smaller in value than key
        findPreSuc(root->right, pre, suc, key);
    }
}