class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
          return ans;
        
        queue<pair<Node*,int>>q;
        map<int,int>m;
        
        q.push(make_pair(root,0)); // root has 0 hd
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            Node* node=p.first;
            int hd=p.second;
            
            if(m.find(hd)==m.end())
                m[hd]=node->data;
            
            if(node->left) q.push({node->left,hd-1});
            if(node->right) q.push({node->right,hd+1});
        }
        
        for(auto x:m)
            ans.push_back(x.second);
        return ans;
    }

};
