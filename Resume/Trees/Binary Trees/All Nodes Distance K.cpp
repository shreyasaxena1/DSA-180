class Solution {
public:
    
    void makeParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){

            TreeNode* curr=q.front();
            q.pop();
            
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
            
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        
        makeParents(root,parent_track);
        
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        
        q.push(target);
        visited[target]=true;
        
        int dis=0;
        
        while(!q.empty()){
            if(dis==k) break;
            dis++;
            
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]){
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && !visited[curr->right]){
                     visited[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                     visited[parent_track[curr]]=true;
                    q.push(parent_track[curr]);
                }
            }
        }
          vector<int>ans;
                             
         while(!q.empty()){
             TreeNode *curr=q.front();
             q.pop();
             ans.push_back(curr->val);
         }
        
        
        return ans;
    }
};
