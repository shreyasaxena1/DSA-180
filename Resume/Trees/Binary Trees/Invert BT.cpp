//Same as Convert to its mirror image
class Solution {
public:
    void invertTreeUtil(TreeNode* root){
        if(root==NULL)
            return;
        
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
    
        invertTree(root->left);
        invertTree(root->right);
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        invertTreeUtil(root);
        return root;
    }
};
