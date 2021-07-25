//Sumit sir's Logic

class Solution {
public:
  int wordBreak(string A, vector<string> &B) {
    int dp[A.length()] = {0};

    for (int i = 0; i < A.length(); i++) {
      for (int j = 0; j <= i; j++) {
        string wordCheck = A.substr(j, i - j + 1);
        for (int k = 0; k < B.size(); k++) {
          if (B[k] == wordCheck) {
            if (j > 0)
              dp[i] += dp[j - 1];
            else
              dp[i] += 1;
          }
        }
      }
    }
    return dp[A.length() - 1] > 0;
  }
};