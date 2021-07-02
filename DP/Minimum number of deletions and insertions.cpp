class Solution
{

public:
    int LCS(string a, string b, int n, int m)
    {
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if (a[i - 1] == b[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
    int minOperations(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        int lcs = LCS(str1, str2, n, m);

        int insertion = m - lcs;
        int deletion = n - lcs;

        return insertion + deletion;
    }
};