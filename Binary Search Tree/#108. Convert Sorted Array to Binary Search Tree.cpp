//https://youtu.be/qoQE3hAdPFs
//If array is not sorted - sort it and do this

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        return bst(nums, 0, nums.size() - 1);
    }
    TreeNode *bst(vector<int> &nums, int low, int high)
    {
        if (low > high)
            return NULL;

        int mid = (low + high) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = bst(nums, low, mid - 1);
        node->right = bst(nums, mid + 1, high);
        return node;
    }
};