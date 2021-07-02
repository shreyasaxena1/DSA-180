class Solution
{
public:
    //Function to find length of shortest common supersequence of two strings.
    int LCS(string X, string Y, int n, int m)
    {
        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
    int shortestCommonSupersequence(string X, string Y, int n, int m)
    {
        return n + m - LCS(X, Y, n, m);
    }
};