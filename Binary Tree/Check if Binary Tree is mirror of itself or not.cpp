//Iterative
//Solved at gfg TC -O(N) SC-O(N)

class Solution
{
public:
    int areMirror(Node *a, Node *b)
    {
        stack<Node *> s1, s2;

        while (1)
        {
            while (a && b)
            {
                if (a->data != b->data)
                    return 0;

                s1.push(a);
                s2.push(b);

                a = a->left;
                b = b->right;
            }
            //any extra node is present in either of tree but is not in other
            //Means not mirror
            if (a || b)
                return 0;

            if (!s1.empty() && !s2.empty())
            {
                //Last node they were pointing before null
                a = s1.top();
                b = s2.top();

                s1.pop();
                s2.pop();

                /*we have visited the node and its left subtree.
               Now, it's right subtree's turn*/

                a = a->right;

                /*we have visited the node and its right subtree.
               Now, it's left subtree's turn*/

                b = b->left;
            }
            else
                break;
        }
        return 1;
    }
};