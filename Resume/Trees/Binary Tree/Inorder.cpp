class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*>s;
        vector<int>ans;
    TreeNode *curr=root;
        
        while(curr||!s.empty()){

            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            ans.push_back(curr->val);
            s.pop();
            curr = curr->right;
        }
        return ans;
    }
};
