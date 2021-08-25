//Sumit Sir explained - https://youtu.be/tRpkluGqINc

class Solution
{
public:
    bool isSubsetSum(int n, int arr[], int sum)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                if (i == 0 && j == 0) //first cell (0,0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else if (j == 0)
                    dp[i][j] = true;
                else
                {
                    //did not bat
                    if (dp[i - 1][j] == true)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        int val = arr[i - 1];
                        //check if element has size smaller or equals to sum asked
                        if (val <= j)
                        {
                            if (dp[i - 1][j - val] == true)
                                dp[i][j] = true;
                        }
                    }
                }
            }
        }
        return dp[n][sum];
    }
};
