class Solution
{
public:
    int equalPartition(int n, int arr[])
    {
        int arraySum = 0;
        for (int i = 0; i < n; i++)
            arraySum += arr[i];
        if (arraySum % 2 != 0)
            return 0;

        int target = arraySum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    if (dp[i - 1][j] == 1)
                        dp[i][j] = 1;
                    else
                    {
                        int val = arr[i - 1];
                        if (val <= j)
                        {
                            if (dp[i - 1][j - val] == 1)
                                dp[i][j] = 1;
                        }
                    }
                }
            }
        }
        return dp[n][target];
    }
};