class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    bool isBSTUtil(Node* root, int min , int max){
        if(root==NULL) 
           return true;
        
        if(root->data <= min || root->data >= max) 
           return false;
        
        if(min>max)
           return false;
           
        return isBSTUtil(root->left,min,root->data) && 
               isBSTUtil(root->right,root->data,max);
        
    }
    
    bool isBST(Node* root) 
    {
        return isBSTUtil(root,INT_MIN,INT_MAX);
    }
};
