class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
       if(root==NULL) return ans;
       queue<TreeNode*>q;
       q.push(root);
       
       while(!q.empty()){
           int size=q.size();
           for(int i=1;i<=size;i++){
               TreeNode* temp=q.front();
               q.pop();
               if(i==size)
                   ans.push_back(temp->val);
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
           }
       }
        return ans;
    }
};
