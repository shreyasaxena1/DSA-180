//Solved at GFG
//TC - O(n)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            curr_sum = curr_sum + nums[i];
            if (curr_sum < nums[i])
                curr_sum = nums[i];

            if (max_sum < curr_sum)
                max_sum = curr_sum;
        }
        return max_sum;
    }
};