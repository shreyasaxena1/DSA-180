//GFG Article

int areMirror(Node *a, Node *b)
{
    /* Base case : Both empty */
    if (a == NULL && b == NULL)
        return true;

    // If only one is empty
    if (a == NULL || b == NULL)
        return false;

    return a->data == b->data &&
           areMirror(a->left, b->right) &&
           areMirror(a->right, b->left);
}