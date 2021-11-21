class Solution {
public:
    int preIndex=0;
    TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder ,int ins,int ine){
        if(ins>ine) return NULL;
        
        TreeNode *root= new TreeNode(preorder[preIndex]);
        
        int inIndex;
        for(int i=ins;i<=ine;i++){
            if(inorder[i]==preorder[preIndex]){
                  inIndex=i;
                break;
           }
        }
        preIndex++;
        root->left=buildTreeUtil(preorder,inorder,ins,inIndex-1);
        root->right=buildTreeUtil(preorder,inorder,inIndex+1,ine);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeUtil(preorder,inorder,0,inorder.size()-1);
    }
};
