//Sumit sir's logic

class Solution
{
public:
    long long int count(int arr[], int m, int n)
    {
        //n-sum m-size of array
        long long int dp[n + 1] = {0};
        dp[0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = arr[i]; j < n + 1; j++)
            {
                dp[j] += dp[j - arr[i]];
            }
        }
        return dp[n];
    }
};

//Both are same , just sumit sir reduce 2D space by updating row everytime

//Aditya verma sir's logic

int getMaxNumberOfWays(int coins[], int n, int sum)
{
    int t[n + 1][sum + 1];
    // initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (coins[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
            else
                t[i][j] = t[i - 1][j];

    return t[n][sum];
}