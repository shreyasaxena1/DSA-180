class Solution
{
    int dp[1002][1002];

public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));

        return lcsUtil(s1, s2, n, m);
    }

    int lcsUtil(string s1, string s2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + lcsUtil(s1, s2, n - 1, m - 1);
        else
            return dp[n][m] = max(lcsUtil(s1, s2, n, m - 1), lcsUtil(s1, s2, n - 1, m));
    }
};