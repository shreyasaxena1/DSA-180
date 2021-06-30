//Coin Change-2

class Solution
{
public:
    int minCoins(int coins[], int M, int V)
    {
        int dp[M + 1][V + 1];

        for (int i = 0; i <= M; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                if (j == 0)
                    dp[i][j] = 0;
                if (i == 0)
                    dp[i][j] = INT_MAX - 1;
                if (i == 1)
                {
                    if (j % coins[i - 1] == 0)
                        dp[i][j] = j / coins[i - 1];
                    else
                        dp[i][j] = INT_MAX - 1;
                }
            }
        }
        dp[0][0] = 0;
        for (int i = 2; i <= M; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                int val = coins[i - 1];
                if (val <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - val], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[M][V] == INT_MAX - 1 ? -1 : dp[M][V];
    }
};