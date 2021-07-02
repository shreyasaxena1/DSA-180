class Solution
{
public:
    int LCS(string a, int n)
    {
        int dp[n + 1][n + 1];
        string b = a;
        reverse(b.begin(), b.end());
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if (a[i - 1] == b[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        return LCS(s, n);
    }
};