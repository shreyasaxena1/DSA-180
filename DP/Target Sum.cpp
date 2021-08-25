class Solution
{
public:
    int countSubsetsWithSum(vector<int> nums, int sum, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= sum; j++)
            dp[0][j] = 0;

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[0].size(); j++)
            {

                int val = nums[i - 1];
                if (val <= j)
                {
                    dp[i][j] = dp[i - 1][j - val] + dp[i - 1][j];
                }

                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][sum];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sumOfArray = 0;

        for (int i = 0; i < n; i++)
            sumOfArray += nums[i];

        if ((sumOfArray + (long)target) % 2 == 1 || sumOfArray < target)
            return 0;
        int sum = (target + sumOfArray) / 2;
        return countSubsetsWithSum(nums, sum, n);
    }
};