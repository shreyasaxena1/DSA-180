class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        
        queue<pair<Node*,int>>q;
        map<int,int>m;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            
            Node *node=p.first;
            int hd=p.second;
            
            m[hd]=node->data;
            
            if(node->left) q.push({node->left,hd-1});
            if(node->right) q.push({node->right,hd+1});
        }
        
        for(auto x:m)
          ans.push_back(x.second);
        
        return ans;
    }
};
