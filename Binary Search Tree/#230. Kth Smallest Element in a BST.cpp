//Not implemented but optimal solution

node *insert(node *root, int data)
{

    if (root == NULL)
        return new node(data);
    if (data < root->data)
    {
        root->left = insert(root->left, data);
        root->lcount++;
    }
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

node *kthsmallest(node *root, int k)
{
    if (root == NULL)
        return NULL;

    int count = root->lcount + 1;
    if (count == k)
        return root;
    if (count > k)
        return kthsmallest(root->left, k);

    return kthsmallest(root->right, k - count);
}

//Optimal , solved at gfg
// TC-O(H) SC-O(H) sc due to recursion

class Solution
{
public:
    int kthSmallestUtil(TreeNode *root, int &k)
    {
        if (root == NULL)
            return 0;
        int left = kthSmallestUtil(root->left, k);
        if (left) //if left is non zero value , means we get our our element
            return left;

        k--;
        if (k == 0)
            return root->val;

        int right = kthSmallestUtil(root->right, k);
        return right;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        return kthSmallestUtil(root, k);
    }
};