/*
class Solution {
public:
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
         if(root==NULL) return 0;
         if(root->val >= low && root->val <= high)
             sum+=root->val;
         
         if(root->val > low){
             rangeSumBST(root->left,low,high);
         }
         if(root->val< high)
             rangeSumBST(root->right,low,high);
         
        return sum;
    }
};
*/


class Solution {
public:
   
    int rangeSumBST(TreeNode* root, int low, int high) {
         if(root==NULL) return 0;
         
         if(root->val > high)
             return rangeSumBST(root->left,low,high);
         
         else if(root->val < low)
             return rangeSumBST(root->right,low,high);
         
        return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high); //in the range
         
    }
};
