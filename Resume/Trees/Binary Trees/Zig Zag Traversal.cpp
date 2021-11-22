class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(!root) return ans;
        
        bool side=true;
        queue<TreeNode*>q;
        stack<int>s;
        
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            for(int i=1;i<=size;i++){
                TreeNode *f=q.front();
                q.pop();
                if(side)
                    temp.push_back(f->val);
                
                else
                    s.push(f->val);
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            while(!s.empty()){
                temp.push_back(s.top());
                s.pop();
            }
            
            ans.push_back(temp);
            side=!side;
        }
        return ans;  
    }
};
