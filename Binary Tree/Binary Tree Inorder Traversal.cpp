//TC - O(N) SC-O(N)

class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        stack<Node *> s;

        Node *curr = root;

        while (curr != NULL || s.empty() == false)
        {

            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            ans.push_back(curr->data);
            s.pop();
            curr = curr->right;
        }

        return ans;
    }
};