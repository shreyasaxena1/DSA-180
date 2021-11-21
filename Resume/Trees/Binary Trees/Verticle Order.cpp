//TUF Explanation
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       queue<pair<TreeNode*,pair<int,int>>>q;
       map<int, map<int, multiset<int>>> nodes;
       
        q.push({root,{0,0}});
        
       while(!q.empty()){
           auto p = q.front();
           q.pop();
           
           TreeNode *temp = p.first;
           int v=p.second.first , l=p.second.second;
           
           nodes[v][l].insert(temp->val);
           
           if(temp->left){
               q.push({temp->left,{v-1,l+1}});
           }
           if(temp->right){
               q.push({temp->right,{v+1,l+1}});
           }  
       }
        
        
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                          //insert at end              
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
