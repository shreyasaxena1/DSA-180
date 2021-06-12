//Sumit sir explained
//TC - O(N2) SC - O(N2) Using DP

class Solution
{
public:
    int countSubstrings(string s)
    {

        vector<vector<int>> dp(s.length(), vector<int>(s.length()));

        int i, j, count = 0;

        for (int gap = 0; gap < s.length(); gap++)
        {
            for (i = 0, j = gap; j < dp.size(); i++, j++)
            {

                if (gap == 0) //1 length string - always be palindrome!
                {
                    dp[i][j] = 1;
                }
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }

                if (dp[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};