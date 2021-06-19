//GFG solved - Perfect Sum Problem

class Solution
{

public:
    int perfectSum(int arr[], int n, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));

        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1; //first cell (0,0)
                else if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    int val = arr[i - 1];
                    if (val <= j)
                        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - val]) % 1000000007;

                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};