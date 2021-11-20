class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
          bool xFind=false,yFind=false;
          int ix,iy;
            
          int size=q.size();
          for(int i=0;i<size;i++){
              TreeNode *temp=q.front();
              q.pop();
              
              if(temp->left){
                  q.push(temp->left);
                  if(temp->left->val==x) {xFind=true,ix=i;}
                  if(temp->left->val==y) {yFind=true,iy=i;}
              }
              if(temp->right){
                  q.push(temp->right);
                  if(temp->right->val==x) {xFind=true,ix=i;}
                  if(temp->right->val==y) {yFind=true,iy=i;}
              }
              
              if(xFind && yFind && ix!=iy) return true; 
              
          }
        }
        return false;
    }
};
