class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {

    int coinsReq = 0, n = coins.size();
    sort(coins.begin(), coins.end());
    for (int i = n - 1; i >= 0; i--) {

      while (coins[i] <= amount) {
        amount -= coins[i];
        coinsReq++;
      }
    }
    return amount == 0 ? coinsReq : -1;
  }
};