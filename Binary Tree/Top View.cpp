class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<pair<Node *, int>> q;
        map<int, int> m;

        q.push(make_pair(root, 0)); // root has 0 hd

        while (!q.empty())
        {
            pair<Node *, int> p = q.front();
            q.pop();

            Node *temp = p.first;
            int hd = p.second;

            if (m.find(hd) == m.end())
                m[hd] = temp->data;

            if (temp->left)
                q.push(make_pair(temp->left, hd - 1));
            if (temp->right)
                q.push(make_pair(temp->right, hd + 1));
        }

        for (auto i = m.begin(); i != m.end(); i++)
            ans.push_back(i->second);

        return ans;
    }
};
