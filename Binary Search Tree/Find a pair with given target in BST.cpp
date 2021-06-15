//TC - O(N)  SC - O(H)
//Kashis M. video
class Solution
{
public:
    // root : the root Node of the given BST
    // target : the target sum
    void pushElements(Node *root, stack<Node *> &s, int direction)
    {
        //Direction 1 - Inorder Direction 0 - Reverse inorder
        if (direction)
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
        }
        else
        {
            while (root)
            {
                s.push(root);
                root = root->right;
            }
        }
    }

    int isPairPresent(struct Node *root, int target)
    {
        stack<Node *> s1, s2;

        int x, y;

        pushElements(root, s1, 1);
        pushElements(root, s2, 0);

        while (!s1.empty() && !s2.empty() && s1.top()->data < s2.top()->data)
        {
            x = s1.top()->data;
            y = s2.top()->data;
            if (x + y == target)
                return true;
            else if (x + y < target)
            {
                Node *temp = s1.top();
                s1.pop();
                pushElements(temp->right, s1, 1);
            }
            else
            {
                Node *temp = s2.top();
                s2.pop();
                pushElements(temp->left, s2, 0);
            }
        }
    }
};