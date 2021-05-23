//Using DP
//Solved at Leetcode
//TC - O(m*n) SC- O(m*n)

class Solution
{
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
    {

        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        else
            return dp[i][j] = countPaths(i + 1, j, m, n, dp) + countPaths(i, j + 1, m, n, dp);
    }
    int uniquePaths(int m, int n)
    {
        int count;
        vector<vector<int>> dp(m);

        for (int i = 0; i < m; i++)
        {
            int col = n;
            dp[i] = vector<int>(col);
            for (int j = 0; j < col; j++)
            {
                dp[i][j] = -1;
            }
        }

        count = countPaths(0, 0, m, n, dp);
        return count;
    }
};

//Optimal Approach
//TC - O(n-1) or O(m-1) SC - O(1)

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int N = m + n - 2;
        int R = m - 1;
        double ans = 1;

        for (int i = 1; i <= R; i++)
        {
            ans = ans * (N - R + i) / i;
        }

        return (int)ans;
    }
};