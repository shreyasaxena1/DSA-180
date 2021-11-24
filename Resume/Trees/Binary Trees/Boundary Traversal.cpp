class Solution {
public:
    
    bool isLeaf(Node *node){
        return !node->left && !node->right;
    }
    
    void getLeftBoundary(Node *root,vector<int>&ans){
        Node *curr=root->left;
        
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    
    void getLeafNodes(Node *root, vector<int>&ans){
        
      
        
        if(isLeaf(root)){
          ans.push_back(root->data);
          return;
        }
        if(root->left)  getLeafNodes(root->left,ans);
        if(root->right) getLeafNodes(root->right,ans);
    }
    
    void getRightBoundary(Node *root,vector<int>&ans){
        Node *curr=root->right;
        stack<int>s;
        while(curr){
            if(!isLeaf(curr)) s.push(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        
        if(root==NULL) return ans;
        
        
        if(!isLeaf(root)) ans.push_back(root->data);
        
        getLeftBoundary(root,ans);
        getLeafNodes(root,ans);
        getRightBoundary(root,ans);
        
        return ans;
    }
};
