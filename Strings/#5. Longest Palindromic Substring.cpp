class Solution
{
public:
    string longestPalindrome(string s)
    {
        //Dp table initialize
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));
        string longestSubstring;
        int i, j, len = 0;

        for (int gap = 0; gap < s.length(); gap++)
        {
            for (i = 0, j = gap; j < dp.size(); i++, j++)
            {
                if (gap == 0)
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
                {
                    if (len < gap + 1) // length of new palindrome is same so we need not to update result
                    {
                        len = gap + 1;
                        longestSubstring = s.substr(i, gap + 1);
                    }
                }
            }
        }
        return longestSubstring;
    }
};