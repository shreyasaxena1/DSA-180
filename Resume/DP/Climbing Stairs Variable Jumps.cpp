int cs(int arr[], int n){
   int dp[n + 1] = {0}; 

  dp[n] = 1;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j <= arr[i]; j++) 
      if (i + j <= n) 
        dp[i] += dp[i + j];
  }
return dp[0];
}
 
