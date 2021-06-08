//TC - O(N) SC - O(H)

class Solution
{
public:
    Node *prev = NULL;
    //Function to convert binary tree to doubly linked list and return it.
    Node *bToDLL(Node *root)
    {
        if (root == NULL)
            return root;

        Node *head = bToDLL(root->left);
        if (prev == NULL) //left is null and this node is head
            head = root;

        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        bToDLL(root->right);

        return head;
    }
};