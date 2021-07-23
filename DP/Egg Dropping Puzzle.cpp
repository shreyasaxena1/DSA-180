class Solution {
public:
  int eggDrop(int n, int k) {
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        if (i == 1)
          dp[i][j] = j;
        else if (j == 0 || j == 1)
          dp[i][j] = j;
        else {
          int minV = INT_MAX;
          for (int a = j - 1, b = 0; a >= 0; a--, b++) {
            int v1 = dp[i][a];
            int v2 = dp[i - 1][b];
            int val = max(v1, v2);
            minV = min(minV, val);
          }
          dp[i][j] = minV + 1;
        }
      }
    }
    return dp[n][k];
  }
};