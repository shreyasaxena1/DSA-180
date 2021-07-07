class Solution {
public:
  int dp[1001][1001];
  bool isPalindrome(string s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++, j--;
    }
    return true;
  }
  int solve(string s, int i, int j) {
    if (i >= j || isPalindrome(s, i, j)) {
      dp[i][j] = 0;
      return 0;
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
      int temp_ans = solve(s, i, k) + solve(s, k + 1, j) + 1;
      ans = min(ans, temp_ans);
    }

    return dp[i][j] = ans;
  }
  int palindromicPartition(string str) {
    int n = str.length();
    memset(dp, -1, sizeof(dp));
    return solve(str, 0, n - 1);
  }
};