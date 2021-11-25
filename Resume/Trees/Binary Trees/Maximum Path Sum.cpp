class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    
    int findMaxSumUtil(Node* root, int &maxi){
        if(!root) return 0;
       
       int leftSum = max(0,findMaxSumUtil(root->left,maxi));
       int rightSum = max(0,findMaxSumUtil(root->right,maxi));
       
       maxi=max(maxi,root->data+leftSum+rightSum);
      
       return root->data+max(leftSum,rightSum);
    }
    
    int findMaxSum(Node* root)
    {
       
       int maxi=INT_MIN;
       
       findMaxSumUtil(root,maxi);
       
       return maxi;
    }
};
