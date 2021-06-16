//TC - O(N)  SC-O(H)

struct bst
{
    bool isBst;
    int size;
    int min;
    int max;
};

bst largestBstUtil(Node *root)
{
    if (!root)
        return {true, 0, INT_MAX, INT_MIN};

    bst l = largestBstUtil(root->left);
    bst r = largestBstUtil(root->right);

    if (l.isBst && r.isBst && root->data > l.max && root->data < r.min)
    {
        bst b = {true, l.size + r.size + 1, min(root->data, l.min), max(root->data, r.max)};
        return b;
    }
    //not bst       //maximum size bst in left n right
    bst b = {false, max(l.size, r.size), -1, -1};
    return b;
}
int largestBst(Node *root)
{
    bst b = largestBstUtil(root);

    return b.size;
}