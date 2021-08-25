class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N + 1][W + 1];
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                int item = wt[i - 1];
                if (item <= j)
                {
                    dp[i][j] = max(val[i - 1] + dp[i][j - item], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][W];
    }
};