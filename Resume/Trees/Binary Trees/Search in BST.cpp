//Leetcode

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        
        if(val > root->val)
            return searchBST(root->right , val);
        
        if(val < root->val)
            return searchBST(root->left,val);
        return root;
    }
};

//GFG

bool search(struct Node* root, int x) {
    if(root==NULL) return false;
    return root->data==x || search(root->left,x) || search(root->right,x);  
}
